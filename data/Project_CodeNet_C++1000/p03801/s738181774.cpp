#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define all(a) a.begin(),a.end()
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const long long MOD = 1000000007, INF = 1e17;
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
//******************************************************************************
template<typename T>vector<T>
make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}

int N;
map<int,int>mp;

signed main()
{
	//IOS();
	cin>>N;
	vpint a;
	rep(i,0,N){
		int t;
		cin>>t;
		if(!mp.count(t)){
			a.push_back({t,i});
		}
		mp[t]++;
	}
	a.push_back({0,INF});
	sort(all(a));
	reverse(all(a));
	vector<int>ans(N,0);
	int sum = 0,mi=INF;
	rep(i,0,a.size()-1){
		sum+=mp[a[i].fi];
		chmin(mi,a[i].se);
		ans[mi]+=(a[i].fi-a[i+1].fi)*sum;
	}
	rep(i,0,N){
		cout<<ans[i]<<endl;
	}
}
