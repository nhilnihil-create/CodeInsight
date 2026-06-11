#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool dp[100010]={0};
    string div[] = { "dream", "dreamer", "erase", "eraser" };
	string S; cin >> S;
	dp[0] = 1;
	for (int i = 0; i < S.size(); ++i) {
		if (!dp[i]) continue;
		for (string s : div) {
			if (s == S.substr(i, s.size())) {
				dp[i + s.size()] = 1;
			}
		}
	}
	cout << (dp[S.size()] ? "YES" : "NO") << endl;
    return 0;
}
