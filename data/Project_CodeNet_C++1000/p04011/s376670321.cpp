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
const int MAX = 1e5+5;

int main(int argc, char ** argv) {
	int N, K, X, Y;
	scanf("%d%d", &N, &K);
	scanf("%d%d", &X, &Y);
	printf("%d\n", min(N, K)*X+max(0, N-K)*Y);
	return 0;
}
