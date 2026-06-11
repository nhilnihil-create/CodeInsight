#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

vector<vector<ll> > v(100000);
ll dis1[100000];
ll disn[100000];
bool maki[100000],niko[100000];

void dfs1(ll n,ll d){
    dis1[n]=d;
    maki[n]=true;
    int eri=v[n].size();
    for(int i=0;i<eri;i++){
        if(!maki[v[n][i]]){
            dfs1(v[n][i],d+1);
        }
    }
    return;
}
void dfsn(ll n,ll d){
    disn[n]=d;
    niko[n]=true;
    int eri=v[n].size();
    for(int i=0;i<eri;i++){
        if(!niko[v[n][i]]){
            dfsn(v[n][i],d+1);
        }
    }
    return;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    memset(maki,0,sizeof(maki));
    memset(niko,0,sizeof(niko));
    ll n;
    cin>>n;
    ll a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(0,0);
    dfsn(n-1,0);
    ll num=0;
    for(int i=0;i<n;i++){
        if(dis1[i]<=disn[i])num++;
        else num--;
    }
    cout << ((num>0)?"Fennec":"Snuke")<<endl;
    return 0;
}