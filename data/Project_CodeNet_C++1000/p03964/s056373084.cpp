#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<ll> T(N);
    vector<ll> A(N);
    rep(i,N){
        cin >>  T[i] >> A[i];
    }
    ll Takahashi = T[0];
    ll Aoki = A[0];
    for (int i = 1; i < N; i++){
        ll min_t1;
        ll min_a1;
        if (Takahashi / T[i] > Aoki / A[i]){
            if (Takahashi % T[i] == 0){
                min_t1 = Takahashi;
                min_a1 = A[i] * (min_t1 / T[i]);
            }
            else{
                min_t1 = (Takahashi / T[i] + 1) * T[i];
                min_a1 = A[i] * (min_t1 / T[i]);
            }
        }
        else if (Takahashi / T[i] < Aoki / A[i]){
            if (Aoki % A[i] == 0){
                min_a1 = Aoki;
                min_t1 = T[i] * (min_a1 / A[i]);
            }
            else{
                min_a1 = (Aoki / A[i] + 1) * A[i];
                min_t1 = T[i] * (min_a1 / A[i]);
            }
        }
        else if (Takahashi / T[i] == Aoki / A[i]){
            if (Takahashi % T[i] != 0 || Aoki % A[i] != 0){
                min_t1 = (Takahashi / T[i] + 1) * T[i];
                min_a1 = (Aoki / A[i] + 1) * A[i];
            }
            else{
                min_t1 = Takahashi;
                min_a1 = Aoki;
            }
        }
        Takahashi = min_t1;
        Aoki = min_a1;
    }
    cout << Takahashi + Aoki << endl;
}
