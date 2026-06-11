#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1e9+7;
const ll inf=1e17;
const int INF=1e9;
const double PI=acos(-1);
const double EPS=1e-10;

//n^2かかるのでTLEは注意
template <class T>
vector<vector<T>> comb(T n) {
  vector<vector<T>> v(n+1,vector<T>(n+1,0));
  rep(i,v.size()){
	v[i][0]=1;
	v[i][i]=1;
  }
  FOR(j,1,v.size())FOR(k,1,j){
	v[j][k]=v[j-1][k-1]+v[j-1][k];
  }
  return v;
}

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	ll n,a,b;
	cin>>n>>a>>b;
	vector<ll> v(n);
	map<ll,ll> mp;
	rep(i,n){
		cin>>v[i];
		mp[v[i]]++;
	}
	sort(begin(v),end(v),greater<ll>());
	double ans=0;
	set<ll> st;
	rep(i,a){
		ans+=v[i];
		st.insert(v[i]);
	}
	cout<<setprecision(15)<<ans/double(a)<<endl;
	vector<vector<ll>> ret=comb(n+1);
	if(st.size()==1){
		ll tar=*st.begin();
		ll num=mp[tar];
		ll cnt=0;
		FOR(i,a,min(num,b)+1){	
			cnt+=ret[num][i];
		}
		cout<<cnt<<endl;
	}else{
		ll tar=v[a-1];
		ll num=0;
		rep(i,a){
			if(v[i]==tar) num++;
		}
		cout<<ret[mp[tar]][num]<<endl;
	}
}