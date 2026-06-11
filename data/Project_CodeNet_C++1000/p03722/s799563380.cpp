#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
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
const ll mod=998244353;
ll V,E;
vector<vector<pll> >G(1010);
vector<ll>d(1010);
bool Bellman_Ford(ll s){
    bool f=1;
    d[s]=0;
    ll cnt=0;
    while(true){
        if(cnt==V){
            f=0;break;
        }
        cnt++;
        bool update=0;
        rep(i,V){
            for(auto e:G[i]){
                if(d[i]!=inf*inf&&d[e.first]>d[i]+e.second){
                    d[e.first]=d[i]+e.second;
                    update=true;
                }
            }
        }
        if(!update)break;
    }
    return f;
}
int main(){
    cin>>V>>E;
    rep(i,E){
        ll a,b,c;cin>>a>>b>>c;
        a--;b--;
        G[a].pb(mp(b,-c));
    }
    rep(i,V)d[i]=inf*inf;
    if(Bellman_Ford(0)){
        cout<<-d[V-1]<<endl;
    }else{
        ll k=d[V-1];
        Bellman_Ford(0);
        if(k==d[V-1])cout<<-d[V-1]<<endl;
        else cout<<"inf"<<endl;
    }
}