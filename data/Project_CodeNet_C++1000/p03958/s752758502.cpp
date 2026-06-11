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
	int k,t; cin >> k >> t;
	vp p(t);
	rep(i,t){
		cin >> p[i].fi;
		p[i].se = i;
	}
	int ans=0;
	int b=-1;
	rep(i,k){
		SORT(p);
		REV(p);
		if(p[1].fi==0){
			if(p[0].se==b) ans = p[0].fi;
			else ans = p[0].fi-1;
			break;
		}
		if(p[0].se==b){
			p[1].fi--;
			b = p[1].se;
		}else{
			p[0].fi--;
			b = p[0].se;
		}
	}
	cout << ans << endl;
}
