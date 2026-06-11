#include<bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
	int res = 500;
	for (int i = 0; i < 26; i++)
	{
		string t = s;
		int cnt = 0;
		while (true)
		{
			bool ok = true;
			char c = 'a' + i;
			for (int j = 0; j < t.size(); j++)
			{
				if(t[j] != c) ok = false;
			}
			if(ok) break;
			else {
				cnt++;
				for (int j = 0; j < t.size() - 1; j++)
				{
					if(t[j] == c || t[j+1] == c) t[j] = c;
				}
				t.erase(t.size() - 1);
			}
//			cout << t << endl;
		}
		res = min(res, cnt);
	}

	cout << res << endl;
	return 0;
}
