#include<bits/stdc++.h>
using namespace std;

using ll=long long;
const int LOGN=20;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin>>x[i];

    ll l; int q;
    cin>>l>>q;
    vector<vector<int>> dp(LOGN,vector<int>(n,0));
    for(int i=0;i<n;i++){
        auto it=prev(upper_bound(x.begin(),x.end(),x[i]+l));
        int j=it-x.begin();
        dp[0][i]=j;
    }
    for(int i=0;i+1<LOGN;i++){
        for(int j=0;j<n;j++){
            dp[i+1][j]=dp[i][dp[i][j]];
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a>b) swap(a,b);
        int res=0;
        for(int i=LOGN-1;i>=0;i--){
            if(dp[i][a]<b){
                res+=(1<<i);
                a=dp[i][a];
            }
        }
        res++;
        cout<<res<<"\n";
    }

    return 0;
}