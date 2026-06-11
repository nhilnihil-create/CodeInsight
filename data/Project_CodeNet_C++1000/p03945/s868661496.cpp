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
	string S;
	cin >> S;
	int ans = 0;
	for (int i = 0; i < S.size() - 1; i++) {
		if (S[i] != S[i + 1]) ans++;
	}
	cout << ans << endl;
}
