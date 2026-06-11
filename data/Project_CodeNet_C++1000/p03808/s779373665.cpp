#include "bits/stdc++.h"
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rep(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////

ll n;
Vi a;

Vi tmp;
bool cal(ll id,ll nu = 1){//id番目から引き始める.nu回やる
	if(nu==0)return true;
	ll tp = 1;
	repi(i,id,n){
		tmp[i] -= tp*nu;
		if(tmp[i]<0)return false;
		tp++;
	}
	rep(i,id){
		tmp[i] -= tp*nu;
		if(tmp[i]<0)return false;
		tp++;
	}
	return true;
}

ll sol(ll diffx,ll difn){//そこから1がはじまるパターンが何回?
	ll tp = diffx - difn;
	if(tp%n==0){
		return tp/n;
	}else{
		return INF;
	}
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>n;
	a.resize(n);
	rep(i,n){
		cin>>a[i];
	}
	tmp = a;
	Vi dif(n);//dif[i]:=a[i+1]-a[i]
	ll difx=0;//difのmax
	rep(i,n-1){
		dif[i+1] = a[i+1]-a[i];
		chmax(difx,dif[i+1]);
	}
	dif[0] = a[0] - a[n-1];
	chmax(difx,dif[0]);
	Vi ct(n);
	bool ans = true;
	rep(i,n){
		ll tmp = sol(difx,dif[i]);
		if(tmp==INF){
			ans = false;
			break;
		}
		ct[i] = tmp;
	}
	rep(i,n){
		cal(i,ct[i]);
	}
	ll sum = n*(n+1)/2;
	ll pre = tmp[0];
	rep(i,n){
		if(tmp[i]%sum!=0){
			ans = false;
			break;
		}
		if(tmp[i]!=pre){
			ans = false;
			break;
		}
		pre = tmp[i];
	}
	YES(ans);
	return 0;
}