#include <bits/stdc++.h>

using namespace std;

string s;
long long int cnt[26];
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	int n = s.length();
	long long int res = n;
	res = res*(res + 1)/2;
	for(int i=0;i<n;i++)
	{
		cnt[s[i]-'a']++;
	}
	for(int i=0;i<26;i++)
	{
		res -= ((cnt[i])*(cnt[i]+1)/2);
	}
	res += 1;
	cout << res << '\n';
	return 0;
}