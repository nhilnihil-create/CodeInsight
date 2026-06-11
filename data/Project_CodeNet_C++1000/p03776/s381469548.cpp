#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
//#include <math.h>
#include <string>
#include <numeric>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
#define ll long long
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<n;++i)
#define mrep(i,n) for(ll i=n;i>=0;--i)
#define all(a) (a).begin(),(a).end()
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vb vector<bool>
#define vvb vector<vector<bool> >
#define pl pair<ll,ll>
#define inf 1001001001001001000
//#define mod 1000000007
#define mod 998244353
#define pi 3.1415926535
using namespace std;
struct __INIT{
    __INIT(){
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout<<fixed<<setprecision(15);
    }
}__init;

//根から全頂点への距離
void distfroot(vvl &edges,vl &dist,ll now,ll depth){
    if(dist[now] != -1) return;
    dist[now] = depth;
    for(ll next:edges[now]){
        distfroot(edges,dist,next,depth+1);
    }
}

//頂点からtargetへの道
bool mitifroot(vvl &edges,vl &miti,ll now,ll prev,ll target){
    cout<<now<<" "<<prev<<endl;
    if(now == target) {
        miti.push_back(now);
        return true;
    }
    for(ll next:edges[now]){
        if(next == now) continue;
        if(mitifroot(edges,miti,next,now,target) == true){
            miti.push_back(now);
            return true;
        }
    }
    return false;
}

ll comb(ll a,ll b){
    if(a<b) return 0;
    if(a == b) return 1;
    ll ue = 1,sita = 1;
    rep(i,b){
        sita *= (i+1);
        ue *= a--;
        if(ue%sita == 0){
            ue /= sita;
            sita = 1;
        }
    }
    return ue/sita;
}

int main(void){
    ll n,a,b;
    cin>>n>>a>>b;
    vl v(n);
    rep(i,n) cin>>v[i];
    sort(all(v));
    reverse(all(v));
    ll sum = 0;
    rep(i,a) sum += v[i];
    ll allkosu = count(all(v),v[a-1]);
    ll nakakosu = 0;
    ll ans = 0;
    rep(i,a) if(v[i] == v[a-1]) nakakosu++;
    if(v[a-1] == v[0]){
        rep(i,min(b-a+1,allkosu-nakakosu+1)){
            ans += comb(allkosu,nakakosu+i);
        }
    }
    else{
        ans = comb(allkosu,nakakosu);
    }
    cout<<(double)sum/a<<endl;
    cout<<ans<<endl;
}