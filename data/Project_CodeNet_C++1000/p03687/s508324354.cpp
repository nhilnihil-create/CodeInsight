#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

//using Graph = vector<vector<edge>>;
using dou =long double;
string yes="yes";
string Yes="Yes";
string YES="YES";
string no="no";
string No="No";
string NO="NO";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define rep(i, n)         for(ll i = 0; i < (ll)(n); i++)
#define brep(n)           for(int bit=0;bit<(1<<n);bit++)
#define erep(i,container) for (auto i : container)
#define irep(i, n)        for(ll i = n-1; i >= (int)0; i--)
#define rrep(i,m,n) for(ll i = m; i < (ll)(n); i++)
#define reprep(i,j,h,w) rep(i,h)rep(j,w)
#define all(x) (x).begin(),(x).end()
#define VEC(type,name,n) std::vector<type> name(n);rep(i,n)std::cin >> name[i];
#define pb push_back
#define pf push_front
#define query int qq;std::cin >> qq;rep(qqq,qq)
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
#define case std::cout <<"Case #" <<qqq+1<<": "
#define RES(a,i,j) a.resize(i);rep(ii,i)a[ii].resize(j); 
#define as assign
#define ffor for(;;)
#define ppri(a,b) std::cout << a<<" "<<b << std::endl
#define pppri(a,b,c) std::cout<<a<<" "<<b<<" "<<c<<std::endl
#define aall(x,n) (x).begin(),(x).begin()+(n)
#define ssum(a) accumulate(a,0ll) 
#define gre(n) greater<n>()

typedef long long ll;
//
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
//typedef long long T;
const int INF = 1000000000;
const double dINF = 1000000000;
const ll INF64 = 922337203685477580ll;
const ll MOD = 1000000007ll;
//const ll MOD = 998244353ll;
const dou pi=3.141592653589793*2;
int main(){
    string s;
    std::cin >> s;
    std::vector<std::vector<int> > a(26);
    int n=s.size();
    rep(i,26){
        a[i].pb(-1);
    }
    rep(i,n){
        a[s[i]-'a'].pb(i);
    }
    itn cnt=0;
    rep(i,26){
        if(a[i].size()-1)cnt++;
        a[i].pb(n);
    }
    if(cnt==1){
        std::cout << 0 << std::endl;
        exit(0);
    }
    
    std::vector<std::vector<int> > aa(26);
    rep(i,26){
        rep(j,a[i].size()-1){
            aa[i].pb(a[i][j+1]-a[i][j]);
        }
    }
    int ans=INF;
    rep(i,26){
        int d=0;
        //std::cout << aa[i].size() << std::endl;
        if(a[i].size()==2)continue;
        rep(j,aa[i].size()){
            chmax(d,aa[i][j]-1);
        }
        chmin(ans,d);
    }
    std::cout << ans << std::endl;

 
   
}