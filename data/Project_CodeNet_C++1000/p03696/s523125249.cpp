#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; string s; read(n, s);

	int mindeg = 0;

	{
		int deg = 0;
		for (char c : s) {
			if (c == '(') deg++;
			else deg--;
			mindeg = min(mindeg, deg);
		}
		
		string res;
		for (int i = 0; i < -mindeg; i++)
			res += '(';
		res += s;
		for (int i = 0; i < deg - mindeg; i++)
			res += ')';
	
		die(res);
	}
}
