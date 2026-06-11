 #include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int N = s.size();
	vector<int> num( 26 );
	for( int i = 0; i < N; i++ ) {
		num[ s[i] - 'a' ]++;
	}
	int ans = N;
	for( int i = 0; i < 26; i++ ) {
		if( num[i] == 0 ) continue;
		string ss = s;
		int n = N;
		char c = (char)('a' + i);
		int cnt = 0;
		while( 1 ) {
			if( ss == string( n, c ) ) break;
			string t;
			for( int j = 0; j < n - 1; j++ ) {
				if( ss[j] == c || ss[j + 1] == c ) t += c;
				else t += ss[j];
			}
			n--;
			ss = t;
			cnt++;
		}
		ans = min( ans, cnt );
	}

	cout << ans << endl;
}
