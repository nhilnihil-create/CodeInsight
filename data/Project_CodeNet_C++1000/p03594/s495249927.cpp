#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

const string colors = "RYGB";
//const string colors = "0123";

int n;
int m;
int d;

int main () {
	cin >> n >> m >> d;
	if (d % 2 == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				printf ("%c", colors[(i + j) % 2]);
			printf ("\n");
		}
		re 0;
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int k = (j - i) / d;
				if ((j - i) % d != 0 && j < i) k--;
//				if ((i + j) % 2 == 1)
					printf ("%c", colors[(((i + j) / d * 2 + k) % 4 + 4) % 4]);
/*				else
					printf (".");	*/
			}
			printf ("\n");
		}
		re 0;
	}
	return 0;
}
