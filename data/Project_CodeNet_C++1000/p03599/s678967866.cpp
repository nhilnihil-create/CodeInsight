#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    ll a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
    ll ansa=100*a,ansb=0;
    rep(i,31){
        rep(j,31){
            rep(k,101){
                rep(l,101){
                    ll w=100*a*i+100*b*j+c*k+d*l;
                    if(w==0||w>f)continue;
                    ll s=c*k+d*l;
                    if(e*w<(100+e)*s)continue;
                    if(ansb*w<ansa*s){
                        ansa=w;
                        ansb=s;
                    }
                }
            }
        }
    }
    cout<<ansa<<' '<<ansb<<endl;
}