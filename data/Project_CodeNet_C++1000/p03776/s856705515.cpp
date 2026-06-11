#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define fi first
#define se second
#define PI (acos(-1))

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i];if(i<len-1) s<<" ";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){
	int len=d.size();
	rep(i,len){
		s<<d[i]<<endl;
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){
	s<<"{ ";
	for(auto itr=v.begin();itr!=v.end();++itr) {
		if (itr!=v.begin()) {s<< ", ";}
		s<<(*itr);
	}
	s<<" }";
	return s;
}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){
	s<<"{"<<endl;
	for(auto itr=m.begin();itr!=m.end();++itr){
		s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;
	}
	s<<"}"<<endl;
	return s;
}

const ll mod=1e9+7;
const ll inf=1e15;
const int INF=1e9;

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
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a,b;
	cin>>n>>a>>b;
	vector<ll> v(n);
	rep(i,n){
		cin>>v[i];
	}
	sort(begin(v),end(v),greater<ll>());
	double ans=0;
	ll tar=v[a-1];
	int cnt1=0,cnt2=0;
	set<ll> now;
	rep(i,n){
		if(i<=a-1){
			ans+=v[i];
			if(v[i]==tar) cnt2++;
			now.insert(v[i]);
		}
		if(v[i]==tar) cnt1++;
	}
	ans/=(double)a;
	cout<<setprecision(10)<<ans<<endl;
	vector<vector<ll>> ret=comb((ll)60);
	if(now.size()!=1){
		cout<<ret[cnt1][cnt2]<<endl;
	}else{
		ll ans=0;
		FOR(i,a,b+1){
			if(i<=cnt1){
				ans+=ret[cnt1][i];
			}
		}
		cout<<ans<<endl;
	}
}