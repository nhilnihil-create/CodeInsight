#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int cn = (int) s.length() - 2;
	if (s[0] == s[s.length() - 1]) cn--;
	cout << (cn & 1 ? "First\n" : "Second\n");

	return 0;
}

