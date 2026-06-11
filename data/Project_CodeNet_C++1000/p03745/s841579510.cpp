#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    int inc = 0;
    ll ans = 1;
    rep(i, 0, N-1){
        if(inc == -1){
            if(A[i] < A[i+1]){
                ans++;
                inc = 0;
            }
        }else if(inc == 1){
            if(A[i] > A[i+1]){
                ans++;
                inc = 0;
            }
        }else{
            if(A[i] > A[i+1]) inc = -1;
            else if(A[i] < A[i+1]) inc = 1;
        }
    }
    cout << ans << endl;
    return 0;
}