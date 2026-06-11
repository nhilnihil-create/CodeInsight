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
typedef pair<ll, ll> pl;
typedef pair<pl, ii> pli;
const int MAX = 2e2+2;
char s[MAX];
int N, L;

int main(int argc, char * * argv) {
	scanf("%d%d", &N, &L);
	vector<string> a;
	rep(i, 0, N) {
		scanf(" %s", s);
		a.pb(s);
	}
	sort(all(a));
	for(auto x : a)
	    printf(x.c_str());
	printf("\n");
	return 0;
}
