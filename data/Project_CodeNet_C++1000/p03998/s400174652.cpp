#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
	string A, B, C; cin >> A >> B >> C;
	int a = 0, b = 0, c = 0;
	string ans;
	char card = 'a';
	while(1) {
		if(card == 'a') {
			if(a == A.size()) {
				ans = "A";
				break;
			}
			card = A[a];
			a++;
		}
		else if(card == 'b') {
			if(b == B.size()) {
				ans = "B";
				break;
			}
			card = B[b];
			b++;
		}
		else {
			if(c == C.size()) {
				ans = "C";
				break;
			}
			card = C[c];
			c++;
		}
	}
	cout << ans << endl;
	return 0;
}