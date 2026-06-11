#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
	string s; cin >> s;
	int res = 0;
	char pre = s[0];
	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] != pre) {
			res++;
			pre = s[i];
		}
	}
	cout << res << endl;
	return 0;
}
