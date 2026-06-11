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

int my_pow(int a) { return a*a; }

int main(int argc, char ** argv) {
	int ans = (1<<30);
	int N, a[101];
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d", a+i);
	REP(k, -100, 100) {
	    int curr = 0;
	    rep(i, 0, N) curr += my_pow(a[i]-k);
	    ans = min(ans, curr);
	}
	printf("%d\n", ans);
	return 0;
}
