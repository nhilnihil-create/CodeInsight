/***"In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge whom he wants."***/
/*** "ALHAMDULILLAH for Everything..." ***/
#include<bits/stdc++.h>
using namespace std;
#define  fastt      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define  ll         long long
#define  mem(a,b)   memset(a,b,sizeof(a))
ll k, m, dp[102][5005], a[102];
ll calcu(ll i, ll w){
    if(i>=k)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    ll x=0, y=0;
    if(w+a[i]<=m){
        x=a[i]+calcu(i+1, w+a[i]);
    }
    else{
        y=calcu(i+1, w);
    }
    return dp[i][w]=max(x, y);
}

int main()
{
    fastt;
    ll n, i, j, x, y, p=0, s=0, h, f=0;
    m=0;
    cin>>n>>k;

    mem(dp, -1);
    for(i=0; i<k; i++){
        cin>>a[i];
        m+=a[i];
    }
    if(k==1){
        cout<<max(0LL, n-1);
        return 0;
    }
    s=m;
    m/=2;
    x=calcu(0, 0);
    p=s-2*x;
    cout<<max(p-1, 0LL)<<endl;
    return 0;
}

