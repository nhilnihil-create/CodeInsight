#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

/* 特定の文字列t -> w に置換 */
string replace_c(string str, string t, string w)
{
	if(!t.empty())
	{
		size_t pos = 0;
		while ((pos = str.find(t, pos)) != std::string::npos)
		{
			str.replace(pos, t.length(), w);
			pos += w.length();
		}
	}
	return str;
}

int  main()
{
	string s; cin >> s;
	string t = ",";
	string w = " ";
	string ans = replace_c(s, t, w);
	cout << ans << endl;
	return (0);
}
