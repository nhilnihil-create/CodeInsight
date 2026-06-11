#include <bits/stdc++.h>
#define forn(x, n)              for (int x = 0; x < n; x++)
#define forr(x, n)              for (int x = n; x >= 0; x--)
#define fore(x, a, b, c)        for (int x = a; x <= b; x += c)
#define forre(x, a, b, c)       for (int x = a; x >= b; x -= c)
#define clr                     cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define all(container)          (container).begin(), (container).end()
#define rall(container)         (container).rbegin(), (container).rend()
#define FILL(x, val)            memset(x, val, sizeof(x))
#define pb                      push_back
#define eb                      emplace_back
#define fi                      first
#define se                      second
#define mod                     (int)1000000007
#define INF                     (int)0x3f3f3f3f

using namespace std;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

typedef long long i64; 
typedef vector< int > vi;
typedef vector< i64 > vi64;
typedef pair< int, int > pi;
typedef vector< pair< int, int > > vpi;

void crypt() {
	int n; cin >> n;
	i64 a, b, a_val = 0, b_val = 0;
	forn(i, n) {
		cin >> a >> b;
		if (!i) {a_val = a; b_val = b;}
		else {
			i64 x = a_val / a + (a_val % a ? 1 : 0);
			i64 y = b_val / b + (b_val % b ? 1 : 0);
			a_val = a * max(x, y);
			b_val = b * max(x, y);
		}
		trace(a_val, b_val);
	}
	cout << a_val + b_val << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout << setprecision(10);
	cout << fixed;
	int t = 1; 
//	cin >> t;
	while (t--) crypt();
	return 0;
}