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

string s;

bool ck(string st,ll id){
	if(id-1<=0 || id+1>=st.size()-1)return false;
	if(st[id-1]==st[id+1]){
		return false;
	}else{
		return true;
	}
}


ll test(string &s,ll typ){
	string pre = s;
	ll rev;
	if(typ==1)rev = 2;
	else rev = 1;
	ll ans = rev;
	rep(i,s.size()){
		if(ck(s,i)){
			s.erase(i,1);
			ll tmp = test(s,rev);
			s = pre;
			if(tmp==typ){
				ans = typ;
				break;
			}
		}
	}
	return ans;
}


int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	std::cout<<std::fixed<<std::setprecision(30);
	cin>>s;
	ll ans = 0;
	if(s[0]==s[s.size()-1]){
		if(s.size()%2==1)ans = 2;
		else ans = 1;
	}else{
		if(s.size()%2==1)ans = 1;
		else ans = 2;
	}
	if(ans == 1){
		print("First");
	}else{
		print("Second");
	}
	//print(test(s,1));
	return 0;
}