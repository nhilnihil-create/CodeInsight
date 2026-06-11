// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 1e5 + 5;

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	#define int ll
	int I, O, J, L; cin >> I >> O >> J >> J >> L;
	cout << max(2 * (I / 2) + 2 * (J / 2) + 2 * (L / 2), (I > 0 && J > 0 && L > 0) * (2 * ((I - 1) / 2) + 2 * ((J - 1) / 2) + 2 * ((L - 1) / 2) + 3)) + O << endl;

	return 0;
}
