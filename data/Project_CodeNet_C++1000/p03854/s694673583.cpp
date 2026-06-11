#include <bits/stdc++.h>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int N = S.size();
	string s[4] = { "dreamer", "eraser", "dream", "erase" };
	string ans = "YES";
	int i = N;
	while( i > 0 ) {
		int flag = 0;
		for( int j = 0; j < 4; j++ ) {
			int sz = s[j].size();
			if( i - sz >= 0 && S.substr( i - sz, sz ) == s[j] ) {
				flag = 1;
				i -= sz;
				break;
			}
		}
		if( flag == 0 ) {
			ans = "NO";
			break;
		}
	}

	cout << ans << endl;
}
