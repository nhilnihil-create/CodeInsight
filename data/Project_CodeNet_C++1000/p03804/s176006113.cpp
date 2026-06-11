#include <bits/stdc++.h>
#define cout16 cout << setprecision(16) 
#define rep(i,n) for(int i=0;i<n;i++ )
#define rep2(i,f,n) for(int i=f;i<n;i++ )
#define SORT(A) sort(A.begin(),A.end())
#define REV(A) reverse(A.begin(),A.end())
typedef long long int ll;
using vi = std::vector<int>;
using vvi = std::vector<std::vector<int>>;
using vll = std::vector<ll>;
using vvll = std::vector<std::vector<ll>>;
using P = std::pair<int,int>;
using vp = std::vector<P>;
using namespace std;
#define INF 1001001001
#define LL_INF 1001001001001001001
#define fi first
#define se second

int main(void) {
	int n,m; cin >> n >> m;
	vector<string> a(n); rep(i,n) cin >> a[i];
	vector<string> b(m); rep(j,m) cin >> b[j];
	bool ans = false;
	rep(si,n-m+1)rep(sj,n-m+1){
		bool ok = true;
		rep(i,m){
//			cout << a[si+i].substr(sj,m) << endl;
//			cout << b[i] << endl;
			if(a[si+i].substr(sj,m)!=b[i]) ok = false;
		}
		if(ok) ans = true;
	}
	
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
}
