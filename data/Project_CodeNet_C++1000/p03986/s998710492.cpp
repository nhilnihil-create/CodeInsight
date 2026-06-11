#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {
	
	string s;
	cin >> s;

	int k = 0;
	int st = 0;
	rep(i, s.size()) {
		if (s[i] == 'S')k++;
		if (s[i] == 'T' && k > 0) { k--;st++; }
	}

	cout << s.size() - 2 * st << endl;

}