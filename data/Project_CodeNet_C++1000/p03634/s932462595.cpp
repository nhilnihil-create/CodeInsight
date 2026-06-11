//Transit Tree Path

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

signed main (){
    int n;cin>>n;
    vector<vector<P>>g(n);
    rep(i,0,n-1){
        int a,b,c;cin>>a>>b>>c;
        a--;b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    int q,k;cin>>q>>k;k--;
    vector<int>d(n,-1);
    queue<tuple<int,int,int>>b;
    b.push({k,k,0});//現在、前、前からの距離
    d[k]=0;
    while(!b.empty()){
        int e=get<0>(b.front()),r=get<1>(b.front()),t=get<2>(b.front());
        b.pop();
        d[e]=d[r]+t;
        for(auto i:g[e]){
            if(d[i.first]==-1)b.push({i.first,e,i.second});
        }
    }
    rep(i,0,q){
        int z,x;cin>>z>>x;
        z--;x--;
        cout<<d[z]+d[x]<<endl;
    }
    return 0;
}