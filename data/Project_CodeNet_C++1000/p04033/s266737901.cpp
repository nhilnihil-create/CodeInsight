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
	int a, b;
	cin >> a >> b;
	if (a <= 0 && b >= 0) cout << "Zero" << endl;
	else {
		if (b < 0) {
			if ((b - a) % 2 == 0)cout << "Negative" << endl;
			else cout << "Positive" << endl;
		}
		else {
			cout << "Positive" << endl;
		}
	}
}