//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

template<typename T>
ostream& operator<<(ostream& os,const vector<T>& v){
    if(v.empty()){
        os<<"{ }";
        return os;
    }
    os<<"{"<<v.front();
    for(auto itr=++v.begin();itr!=v.end();itr++){
        os<<", "<<*itr;
    }
    os<<"}";
    return os;
}

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

//戻り値: 負の閉路が存在する場合、Trueを返す。
template<typename T>
bool bellman_ford(const vector<vector<pair<int,T>>>& path,vector<T>& dis,int start){
    int n=path.size(),is_null=dis[0];
    int to;
    T cost;
    dis[start]=0;
    for(int i=1;i<=n;i++){
        bool update=false;
        rep(j,n)for(auto e:path[j]){
            tie(to,cost)=e;
            if(dis[j]!=is_null && dis[to]>dis[j]+cost){
                dis[to]=dis[j]+cost;
                update=true;
            }
        }
        if(!update) return false;
        if(i==n) return true;
    }
}

int main(){
    int n,m; cin>>n>>m;
    vector<vector<pair<int,ll>>> path(n);
    vector<ll> dis(n,INF);
    rep(i,m){
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        path[a].push_back(mk(b,-c));
    }
    bellman_ford<ll>(path,dis,0);
    ll ans=dis[n-1];
    dis[0]=INF;
    bellman_ford<ll>(path,dis,0);
    if(ans==dis[n-1]){
        cout<<-ans<<endl;
    }
    else cout<<"inf"<<endl;
}
