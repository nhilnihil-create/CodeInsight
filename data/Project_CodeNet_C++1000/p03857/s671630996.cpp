// g++ macro.cpp -std=c++14
#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;

#define dump(x)  cout << #x << " = " << (x) << endl;
#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl

#define SANKOU(n,a,b) cout << ((n) ? (#a) : (#b) ) << endl

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)

#define FOREACH(x,a) for(auto& (x) : (a) )

#define WFA(d,v) REP(k,v)REP(i,v)REP(j,v)d[i][j]=min(d[i][j],d[i][k]+d[k][j])

#define SCOUT(x) cout<<(x)<<" "
#define ENDL cout<<endl

#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define VECIN2(x,y) REP(i,x.size())cin>>x[i]>>y[i]
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl

#define ALL(obj) (obj).begin(),(obj).end()

#define EXIST(n,x) (find(ALL(n),x)!=n.end())
#define UNIQUE(obj) sort(ALL( obj )); obj.erase(unique(ALL(obj)),obj.end())
#define COUT(x) cout<<(x)<<endl
void CINT(){}
template <class Head,class... Tail>
void CINT(Head&& head,Tail&&... tail){
    cin>>head;
    CINT(move(tail)...);
}
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)

// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision; // cpp_int

#define P pair<int,int>
#define V vector<int>
#define M map<int,int>
#define S set<int>
#define L list<int>

#define pb(a) push_back(a)
#define mp make_pair
class UnionFind{
public:
    V par,rank;// parent,rank
    UnionFind(int n);
    int Find(int x);
    void Unite(int x,int y);
    bool Same(int x,int y);
};
UnionFind::UnionFind(int n){
    par.resize(n);rank.resize(n);
    REP(i,n){par[i]=i;rank[i]=0;}
}
int UnionFind::Find(int x){
    
    return (par[x]==x?x:Find(par[x]));
}
void UnionFind::Unite(int x,int y){
    x=Find(x);y=Find(y);//parent
    
    if(x==y)return;//end
    if(rank[x]<rank[y])par[x]=y;
    else{
        par[y]=x;
        if(rank[x]==rank[y])rank[x]++;
    }
}
bool UnionFind::Same(int x,int y){
    return (Find(x)==Find(y));
}


int main(){

  CIN(n,k,l);V p(k);V q(k);V r(l);V s(l);VECIN2(p,q);VECIN2(r,s);
  REP(i,k){q[i]--;p[i]--;}
  REP(i,l){r[i]--;s[i]--;}
  UnionFind road(n);UnionFind train(n);

  REP(i,k)road.Unite(p[i],q[i]);
  REP(i,l)train.Unite(r[i],s[i]);
  map<P,S> map_;
  REP(i,n)map_[mp(road.Find(i),train.Find(i))].insert(i);
  
  vector<int> ans(n,0);
  FOREACH(x,map_){
    FOREACH(xx,x.second){
      ans[xx] = x.second.size();
    }
  }

  REP(i,n-1)SCOUT(ans[i]);COUT(ans.back());


  return 0;
}
