#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int ch[26];
string a;
int t;
int dp[200010];
int nex[200010][26];
int func(int here) {
	if(here == t)return 0;
	int &ret = dp[here];
	if (ret != -1)
		return ret;
	ret = 1234567890;
	for (int i = 0; i < 26; i++) {
		ret = min(ret, func(nex[here][i]) + 1);
	}
	return ret;
}
void func1(int here) {
	if (here == t)return;
	int ret = 1234567890;
	for (int i = 0; i < 26; i++) {
		ret = min(ret, func(nex[here][i]) + 1);
	}
	for (int i = 0; i < 26; i++) {
		if (ret == func(nex[here][i]) + 1) {
			printf("%c", i + 'a');
			func1(nex[here][i]);
			return;
		}
	}
}
int main()
{
	memset(dp, -1, sizeof(dp));
	ios::sync_with_stdio(false);
	cin.tie(0);
	string b;
	cin >> b;
	a = " " + b;
	t = a.size();
	for (int i = 0; i < 26; i++)
		ch[i] = t;
	for (int i = t - 1; i >= 0; i--) {
		for (int y = 0; y < 26; y++)
			nex[i][y] = ch[y];
		if(i)
			ch[a[i] - 'a'] = i;
	}
	func(0);
	func1(0);
}