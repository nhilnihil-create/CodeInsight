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
	string S, ans;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'B' && !ans.empty()) ans.pop_back();
		else if (S[i] != 'B')ans.push_back(S[i]);
	}
	cout << ans << endl;
}
