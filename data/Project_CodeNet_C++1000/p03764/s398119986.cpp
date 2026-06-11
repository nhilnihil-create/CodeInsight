#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse
// struct Edge {
//   int to, id;
//   Edge(int a, int b): to(a), id(b) {}
// };

ll x[100010],y[100010];

int main(int argc, char const *argv[])
{
	int n,m;cin>>n>>m;

	rep(i,n) cin>>x[i];
	rep(i,m) cin>>y[i];

	ll X=0,Y=0;

	rep(i,n) {
		X += x[i]*(2*i-n+1);
		X%=MOD;
	}

	rep(i,m) {
		Y += y[i]*(2*i-m+1);
		Y%=MOD;
	}

	cout<< X*Y%MOD <<endl;

	return 0;
}