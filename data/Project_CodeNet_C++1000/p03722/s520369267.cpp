#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
const ll inf = 1e+18+1;
struct edge {ll from,to,cost;};
edge es[2000];
ll d[1000];
int V,E;
vector<bool> neg(1000,false);
void vf(){
    rep(i,V) d[i]=inf;
    d[0]=0;
    rep(j,V){
        bool update=false;
        rep(i,E){
            edge e=es[i];
            if(d[e.from]!=inf&&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        if(!update)break;
    }
    return;
}
void solve(){
    rep(j,V){
        rep(i,E){
            edge e=es[i];
            if(d[e.from]!=inf&&d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                if(e.to==V-1){
                    cout<<"inf"<<endl;
                    return;
                }
            }
        }
    }
    ll res=d[V-1];
    cout<<-res<<endl;
}
int main(void){
    cin>>V>>E;
    rep(i,E){
        int a,b;ll c;cin>>a>>b>>c;a--;b--;
        es[i].from=a;es[i].to=b;es[i].cost=-c;
    }
    vf();
    solve();
}