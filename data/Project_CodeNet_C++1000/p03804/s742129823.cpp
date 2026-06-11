#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
#define For(i,a,b) for(ll i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)x.size())
#define MOD (ll)(1e9+7)
#define INF (9e18)
#define EPS (1e-6)
#ifdef LOCAL_TEST
#define debug(...) do{\
	cerr<<__PRETTY_FUNCTION__<<" - "<<__LINE__<<\
	" : ("#__VA_ARGS__<<") = ";\
	_OUT(__VA_ARGS__);\
}while(0)
template<typename T>void _OUT(T x){cerr<<x<<endl;}
template<typename T,typename...I>void _OUT(T x,I ...tail){cerr<<x<<", ";_OUT(tail...);}
#else
#define debug(...)
#endif

void INIT(){
#ifdef LOCAL_TEST
	freopen("D:\\input.in","r",stdin);
	freopen("D:\\output.out","w",stdout);
	freopen("D:\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int fpow(int b,int p){
	b%=MOD;
	int ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int32_t main() {
	INIT();
	//code...
	int n,m; cin>>n>>m;
	vector<string> a(n),b(m);
	for(auto &i:a) cin>>i;
	for(auto &i:b) cin>>i;
	For(x,0,n-m) For(y,0,n-m){
		bool ac=true;
		For(i,x,x+m-1) For(j,y,y+m-1){
			if(a[i][j]!=b[i-x][j-y]){
				ac=false;
				goto END;
			}
		}
	END:
		if(ac){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}
