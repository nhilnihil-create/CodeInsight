#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
	int N,x; cin >> N >> x;
	vector<int> a(2*N);
	rep(i,N){
		cin >> a[i];
		a[i+N] = a[i];
	}
	vector<vector<int>> b(N,vector<int>(N));
	rep(i,N){
		b[0][i] = a[i];
	}
	repr(i,1,N){
		rep(j,N){
			b[i][j] = min(b[i-1][j],a[j+N-i]);
		}
	}
	ll ans = LINF;
	rep(i,N){
		ll now = (ll)x*i;
		rep(j,N){
			now += b[i][j];
		}
		ans = min(ans,now);
	}
	cout << ans << endl;
}

