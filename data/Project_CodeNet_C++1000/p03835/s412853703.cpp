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
const int MOD = 998244353;
const ll INF = 1000000000000000000;


int main()
{
	int K, S;
	cin >> K >> S;
	int ans = 0;
	for (int x = 0; x <= K; x++) {
		for (int y = 0; y <= K; y++) {
			int num = S - x - y;
			if (num >= 0 && num <= K) ans++;
		}
	}
	cout << ans << endl;
}