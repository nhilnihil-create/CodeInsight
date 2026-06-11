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
	int N, A, B;
	cin >> N >> A >> B;
	ll num1 = (ll)A * (N - 1) + B;
	ll num2 = (ll)B * (N - 1) + A;
	if (A > B) cout << 0 << endl;
	else if (N == 1) {
		if (A == B) cout << 1 << endl;
		else cout << 0 << endl;
	}
	else cout << num2 - num1 + 1 << endl;
}