#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	string s;
	cin >> n >> s;


	vs a0 = { "S","W","S","W" };
	vs a1 = { "S","S","W","W" };
	string ans = "";

	rep(k,4){
		
		vs t(n + 2, "");
		t[0] = a0[k];
		t[1] = a1[k];

		rep1(i, n) {
			if ((s[i - 1] == 'o') ^ (t[i] == "W"))t[i + 1] = t[i - 1];
			else if (t[i - 1] == "S")t[i + 1] = "W";
			else t[i + 1] = "S";
		}

		if (t[0] == t[n] && t[1] == t[n + 1]) {
			rep1(i, n)ans += t[i];break;
		}
	}

	if (ans == "")cout << -1 << endl;
	else cout << ans << endl;

}