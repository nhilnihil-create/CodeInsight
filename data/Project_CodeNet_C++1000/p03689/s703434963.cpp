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
string get_str(string s) {
	s+=',';
	string ret="";
	for(int i=0; i<s.size(); i++) {
		if(s[i]==',') ret+="=%ld, ";
		else ret+=s[i];
	}
	return ret;
}
#define dump(...) printf(get_str(#__VA_ARGS__).c_str(),__VA_ARGS__);cout<<endl
 
#define endl '\n'
#define IOS()                     \
	ios_base::sync_with_stdio(0); \
	cin.tie(0)
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
//******************************************************************************
 


signed main()
{
	//IOS();
	int H,W,h,w;
	cin>>H>>W>>h>>w;
	auto a = make_v<int>(H,W);
	if(H%h==0&&W%w==0){
		cout<<"No"<<endl;
		return 0;
	}
	fill_v(a,1000);
	rep(i,0,H){
		if(i%h==h-1){
			rep(j,0,W){
				if(j%w==w-1){
					a[i][j]=-1-(h*w-1)*1000;
				}
			}
		}
	}
	//cout<<sum<<endl;
	{
		cout<<"Yes"<<endl;
		rep(i,0,H){
			rep(j,0,W){
				if(j)cout<<" ";
				cout<<a[i][j];
			}
			cout<<endl;
		}
	}
}
//3 4 2 2