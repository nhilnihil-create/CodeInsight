#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,n) for(int i=1;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define Rrep(i,n) for(int i=n-1;i>0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
#define P pair<int,int>
#define Pll pair<ll,ll>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}


ll COM(int n,int k){
    int pres=n;
    ll pret=1LL;
    int q=2;
    rep(qqqqq,k){
        pret*=pres;
        pres--;
        while(pret%q==0&&q<=k){
            pret/=q; q++;
        }
    }
    while(q<=k){
        pret/=q; q++;
    }
    return pret;
}

int main(){
    int n; cin >> n;
    int a,b; cin >> a >> b;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(ALL(v),greater<ll>());
    int x[n]; x[0]=0;
    Rep(i,n){
        if(v[i]==v[i-1]) x[i]=x[i-1];
        else x[i]=i;
    }
    ll sum[n+1]; sum[0]=0;
    rep(i,n) sum[i+1]=sum[i]+v[i];
    long double ans=0.0;
    for(ll i=a;i<=b;i++){
        if(ans*i<=sum[i])ans=(long double)sum[i]/(long double)i;
    }
    cout << fixed << setprecision(10) << ans << endl;
    ll res=0;
    for(ll i=a;i<=b;i++){
        if(ans==(long double)sum[i]/(long double)i){
            //v[i-1]
            int d=x[i-1];
            int cnt=0;
            rep(j,n){
                if(v[i-1]==v[j]) cnt++;
            }
            //cout << cnt << " " << i << " " << i-d << endl;
            res+=COM(cnt,i-d);
            //cout << res << endl;
        }
    }
    cout << res << endl;
}
