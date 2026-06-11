#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
    ll N,K;
    cin>>N>>K;
    ll ans=1;
    rep(i,N){
        if(i==0){
            ans*=K;
        }
        else {
          ans*=K-1;
        }
    }
    cout<<ans<<endl;
}