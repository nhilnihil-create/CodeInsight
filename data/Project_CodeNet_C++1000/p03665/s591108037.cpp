#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n,p;cin>>n>>p;
    vector<ll> dp(6000,0);
    dp[0]=1;
    rep(i,n){
        int a;cin>>a;
        for(int j=5000;j-a>=0;j--){
            if(dp[j-a]!=0)dp[j]+=dp[j-a];
        }
    }
    ll res=0;
    rep(i,5001){
        if(i%2==p)res+=dp[i];
    }
    cout<<res<<endl;
}