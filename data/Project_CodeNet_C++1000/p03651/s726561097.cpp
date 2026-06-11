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
ll ggd(ll a, ll b) {//最小公倍数，最大公約数
	if(a<b)swap(a,b);
	if (b == 0) {
		return a;			
	}
	return ggd(b, a % b);
}
ll lcm(ll number1,ll number2){
	return number1/ggd(number1,number2)*number2;	
}
int main(){
    int n,k;
    std::cin >> n>>k;
    VEC(int,a,n);
    sort(all(a));
    int ma=a[n-1];
    int d=ggd(a[0],a[1]);
    rep(i,n){
        d=ggd(d,a[i]);
    }
    if(k<=ma&&k%d==0)std::cout << "POSSIBLE" << std::endl;
    else std::cout << "IMPOSSIBLE" << std::endl;
}