#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    ll n,a;
    cin>>n>>a;
    ll x[n+1];
    rep(i,n){
        cin>>x[i+1];
    }
    //dp
    vvvll dp(n+1,vvll(n+1,vll(a*n+1,0)));
    for (int i=0;i<n+1;i++){
        dp[i][0][0]=1;
    }
    //dp[i][j][k]は1~iの中からjまい選んで合計をkになる組みの数になる組みの個数
    for (int i=1;i<n+1;i++){
        for (int j=1;j<i+1;j++){
            for (int k=1;k<a*n+1;k++){
                if (k-x[i]<0){
                    dp[i][j][k]=dp[i-1][j][k];
                }
                else{
                    dp[i][j][k]=dp[i-1][j][k]+dp[i-1][j-1][k-x[i]];
                }
            }
        }

    }
    ll ans=0;
    for (int i=1;i<n+1;i++){
        ans+=dp[n][i][i*a];
    }
    cout<<ans<<endl;

    return 0;
}