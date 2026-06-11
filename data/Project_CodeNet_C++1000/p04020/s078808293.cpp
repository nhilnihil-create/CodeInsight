#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;


int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll cnt = 0;
    /*rep(i,N){
        cnt += A[i]/2;
        A[i] %= 2;
    }*/
    rep(i,N-1){
        ll n = (A[i]+A[i+1]) / 2;
        cnt += n;
        if(A[i+1] == 0){
            continue;
        }else{
            A[i+1] = (A[i]+A[i+1])%2;
            A[i] = 0;
        }
    }
    if(N==1){
        cnt = A[0]/2;
    }
    cout << cnt << endl;
}
