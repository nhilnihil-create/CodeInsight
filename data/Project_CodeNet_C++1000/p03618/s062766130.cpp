#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
const int mod = 1000000007;
#define ll long long

ll cnt[26] = { 0 };
int main()
{
	string S; cin >> S;
	for (int i = 0; i < S.size(); i++) {
		cnt[S[i] - 'a']++;
	}
	ll ans = S.size() * (S.size() - 1) / 2 + 1;
	for (int i = 0; i < 26; i++) {
		ans -= cnt[i] * (cnt[i] - 1) / 2;
	}
	cout << ans << endl;
}