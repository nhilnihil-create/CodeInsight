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


signed main()
{
	//IOS();
	int N,M;
	cin>>N>>M;
	vector<int>a(N);
	int ans = 0;
	rep(i,0,N){
		cin>>a[i];
		if(i){
			if(a[i-1]<a[i])ans+=a[i]-a[i-1];
			else ans+=a[i]+M-a[i-1];
		}
	}
	vector<int>sum(M*2+10,0);
	vector<int>imos(M*2+10,0);
	rep(i,0,N-1){
		if(a[i]>a[i+1]){
			sum[a[i+1]+M]+=a[i+1]+M-a[i]-1;
			imos[a[i]+2]++;
			imos[a[i+1]+M+1]--;
		}else{
			sum[a[i+1]]+=a[i+1]-a[i]-1;
			imos[a[i]+2]++;
			imos[a[i+1]+1]--;
		}
	}
	rep(i,0,M*2){
		imos[i+1]+=imos[i];
	}
	vector<int>cnt(M*2+10,0);
	int ma = 0;
	rrep(i,0,imos.size()){
		cnt[i%M]+=sum[i];
		if(i)sum[i-1]+=sum[i]-imos[i];
		chmax(ma,cnt[i%M]);
	}
	cout<<ans-ma<<endl;
}
