#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    int mode=0;
    int ans=0;
    for (int i = 0; i < N-1; i++){
        if(A[i]<A[i+1]){
            if(mode==2){
                ans++;
                mode=0;
            }
            else mode=1;
        }
        if(A[i]>A[i+1]){
            if(mode==1){
                ans++;
                mode=0;
            }
            else mode=2;
        }
    }
    cout << ans+1 << endl;
}
