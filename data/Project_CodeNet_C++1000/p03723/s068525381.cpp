#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int ans = 0;
	while (true) {
		if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
			cout << ans << endl;
			return 0;
		}
		if (A == B && A == C) {
			cout << -1 << endl;
			return 0;
		}
		int tmpA = A, tmpB = B, tmpC = C;
		A = tmpB / 2 + tmpC / 2;
		B = tmpA / 2 + tmpC / 2;
		C = tmpA / 2 + tmpB / 2;
		ans++;
	}
}
