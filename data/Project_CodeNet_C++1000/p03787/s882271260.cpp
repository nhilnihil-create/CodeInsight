#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline void chmin(T &l,T r){l=min(l,r);}
template <typename T>inline void chmax(T &l,T r){l=max(l,r);}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}
    namespace _DSU{
    int cnt=0;
    int mem[2][212345];
    int* get(){
        return mem[cnt++];
    }
}
class UnionFind{    
public:
    int *par,*rank;
    int find(int x){
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
    }
    UnionFind(int n,int *par,int *rank) :par(par),rank(rank){
	for(int i = 0; i < n; i++)par[i] = i,rank[i] = 0;
    }
    UnionFind(int n):UnionFind(n,_DSU::get(),_DSU::get()){}
    bool unite(int x, int y){
	x = find(x);y = find(y);
	if (x == y)return false;
	if (rank[x] < rank[y]) par[x] = y;
	else{
	    par[y] = x;
	    if (rank[x] == rank[y])rank[x]++;
	}
	return true;
    }
    bool same(int x, int y){
	return find(x) == find(y);
    }
};

int main(){
    int N,M;
    cin>>N>>M;
    UnionFind uf(2*N);
    REP(i,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        uf.unite(a,b+N);
        uf.unite(a+N,b);
    }
    vector<int> cnt(2*N);
    REP(i,2*N)cnt[uf.find(i)]++;
    LL a,b,c;
    a=b=c=0;
    REP(i,2*N){
        if(i<N&&cnt[i]==1)a++;
        else if(cnt[i]>0&&uf.same(i,(i+N)%(2*N)))b++;
        else if(cnt[i]>1)c++;
    }
    c/=2;
    //cout<<a<<b<<c<<endl;
      //  cout<<2*a*(N-a)+a*a<<endl<<c*(c+1)<<endl<<b*c<<endl<<b*(b+1)/2<<endl;    
     cout<<2*a*(N-a)+a*a+2*c*c+2*b*c+b*b<<endl;
    //(bb+2bc+2cc)
    return 0;
}
