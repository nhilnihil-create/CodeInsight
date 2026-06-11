#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<n;i++)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

class UF{
    public:
        vector<int> rank,parent;
        UF(int n) : rank(n,0) , parent(n,0){
            for(int i=0;i<n;i++) parent[i]=i;
        }
        int find_root(int x){
            if(parent[x]==x) return x;
            else return parent[x] = find_root(parent[x]);
        }
        void unite(int x,int y){
            x=find_root(x);
            y=find_root(y);
            if(x==y) return;
            if(rank[x]<rank[y]) parent[x] = y;
            else{
                parent[y]=x;
                if(rank[x]==rank[y])rank[x]++;
            }
        }
        bool same(int x,int y){
            return find_root(x)==find_root(y);
        }
};


ll N,K,L;

int main(){
    cin >> N >> K >> L;
    UF uf1(N),uf2(N);
    rep(i,K){
        int p,q;cin>>p>>q;p--;q--;
        uf1.unite(p,q);
    }
    rep(i,L){
        int r,s;cin>>r>>s;r--;s--;
        uf2.unite(r,s);
    }

    map<pii,int> mp;
    rep(i,N){
        int x = uf1.find_root(i);
        int y = uf2.find_root(i);
        mp[pii(x,y)]++;
    }

    rep(i,N){
        int x = uf1.find_root(i);
        int y = uf2.find_root(i);
        pii p(x,y);
        cout << mp[p] << " ";
    }
    cout << endl;
}
