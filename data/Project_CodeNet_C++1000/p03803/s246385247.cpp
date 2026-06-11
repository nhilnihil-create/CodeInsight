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
	int A, B; cin >> A >> B;
	if(A > B && B != 1) cout << "Alice" << endl;
	else if(A < B && A != 1) cout << "Bob" << endl;
	else if(A == 1 && B != 1) cout << "Alice" << endl;
	else if(B == 1 && A != 1) cout << "Bob" << endl;
	else if(A == B) cout << "Draw" << endl;
	return 0;
}