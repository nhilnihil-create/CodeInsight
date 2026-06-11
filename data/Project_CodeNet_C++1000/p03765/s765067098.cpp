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

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	string s,t;
	cin>>s>>t;
	int n=s.size(),m=t.size();
	vector<int> sum1(n+1,0),sum2(m+1,0);
	rep(i,n){
		if(s[i]=='A') sum1[i+1]=sum1[i]+1;
		if(s[i]=='B') sum1[i+1]=sum1[i]+2;
	}
	rep(i,m){
		if(t[i]=='A') sum2[i+1]=sum2[i]+1;
		if(t[i]=='B') sum2[i+1]=sum2[i]+2;
	}
	int q;
	cin>>q;
	while(q--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--,c--;
		if((sum1[b]-sum1[a])%3==(sum2[d]-sum2[c])%3){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}