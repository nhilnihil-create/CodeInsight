#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;

int main(int argc, char * * argv) {
	int N, K, x, ans = 0;
	scanf("%d%d", &N, &K);
	vector<int> mp(10);
	rep(i, 0, K) {
	    scanf("%d", &x);
	    mp[x] = 1;
	}
	bool ok;
	int n = N;
	while(!ans) {
	    ok = true;
	    N = n;
	    while(N) {
	        if(mp[N%10]) ok = false;
	        N /= 10;
	    }
	    if(ok) ans = n;
	    ++n;
	}
	printf("%d\n", ans);
	return 0;
}
