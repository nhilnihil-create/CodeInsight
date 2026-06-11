#include <bits/stdc++.h>
using namespace std;
struct edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<edge>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(int i = 0; i < (int)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(int i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(int i = m; i < (int)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define itn int
#define mp make_pair
#define sum(a) accumulate(all(a),0ll)
#define keta fixed<<setprecision
#define vvector(name,typ,m,n,a)vector<vector<typ> > name(m,vector<typ> (n,a))
#define vvvector(name,t,l,m,n,a) vector<vector<vector<t> > > name(l, vector<vector<t> >(m, vector<t>(n,a)));
#define vvvvector(name,t,k,l,m,n,a) vector<vector<vector<vector<t> > > > name(k,vector<vector<vector<t> > >(l, vector<vector<t> >(m, vector<t>(n,a)) ));
#define case std::cout << "Case #" <<qqq+1<<": "
#define res resize
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout << a<<" "<<b <<" "<< c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
 
typedef long long ll;
typedef pair<int,int> P;
//typedef long long T;
const int INF = 2000000000;
const ll INF64 = 922337203685477580ll;
const ll MOD = 1000000007ll;
int cc(int n,int bit){
    int c=0;
    rep(i,n){
        if(bit&(1<<i))c++;
    }
    return c;
}

int main(){
    int n,k;
    std::cin >> n>>k;
    VEC(ll,aa,n);
    ll ans=INF64;
    brep(n){
 //       std::cout << cc(n,bit) << std::endl;
        std::vector<ll> a(aa);
        if(cc(n,bit)<k)continue;
        ll m=a[0],d=0ll;
        rrep(i,1,n){
            if(bit&(1<<i)){
                d+=max(0ll,m-a[i]+1);
                a[i]=max(a[i],m+1);
            }
            m=max(m,a[i]);
        }
  //      erep(i,a)std::cout << i << " ";
   //     std::cout << std::endl;
        ans=min(ans,d);
    }
    std::cout << ans << std::endl;
}