#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

const ll INF=1000000000000000;
struct edge{ll from, to, cost;};
vector<edge> es(2000);
vector<ll> d(1000,-INF);
vector<bool> usedV(1000,false),usedE(2000,false);
ll V,E;
bool can=true;

void BellmanFord(ll s){
    d[s]=0;
    ll count=0;
    while (true){
        bool update=true;
        rep(i,E){
            edge e=es[i];
            if (d[e.from]!=-INF&&d[e.to]<d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=false;
                usedV[e.to]=usedV[e.from];
                if (!usedE[i]){
                    usedE[i]=true;
                }
                else {
                    usedV[e.to]=true;
                }
            }
        }
        if (update){
            break;
        }
        else {
            count++;
        }
        if (count==2*E){
            if (usedV[V-1]){
                can=false;
            }
            break;
        }
    }
}

int main(){
    cin >> V >> E;
    rep(i,E){
        ll a,b,c;
        cin >> a >> b >> c;
        a--,b--;
        es[i]=edge{a,b,c};
    }
    BellmanFord(0);
    if (!can){
        cout << "inf" << endl;
    }
    else {
        cout << d[V-1] << endl;
    }
}