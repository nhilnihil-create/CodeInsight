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
	ll a, b, x;
	cin >> a >> b >> x;
	if (a == 0) cout << b / x + 1 << endl;
	else cout << b / x - (a - 1) / x << endl;
}