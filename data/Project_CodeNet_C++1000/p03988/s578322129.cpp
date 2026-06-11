#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

const ll mod = 998244353;

int main() {
	multiset<int> s;
	int N; scanf("%d",&N);
	repp(i,N){
		int x; scanf("%d",&x); s.insert(x);
	}
	while( s.size() >= 2 ){
		int mx = *s.rbegin();

		if( mx <= 0 ){
			printf("Impossible\n");
			return 0;
		}

		int cnt = 0;
		for(auto e : s) if( e == mx ) cnt++;
		if( cnt < 2 || (mx==1&&cnt>=3) || (mx>1&&cnt==sz(s))){
			printf("Impossible\n");
			return 0;
		}
		
		s.erase(mx);
		
		if( sz(s) ){
			int nmx = *s.rbegin();
			if( nmx < mx-1 ){
				printf("Impossible\n");
				return 0;
			}	
		}
		
		vector<int> v; 
		for(auto& e : s) v.pb(e);
		s.clear();
		for(auto e : v) s.insert(e-1);
	}

	if( s.size() == 1 ){
		if( *s.begin() == 0 ){
			printf("Possible\n"); return 0;
		}
		else{
			printf("Impossible\n"); return 0;
		}
	}

	printf("Possible\n");

}
