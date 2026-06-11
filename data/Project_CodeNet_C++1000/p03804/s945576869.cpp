#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 123;
#define int long long 
int n, m;
pair <int, int> a[maxn];
string s[60], t[60];
main () { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    	cin >> s[i];
    for(int i = 0; i < m; i++)
    	cin >> t[i];

	for(int x = 0; x + m - 1 < n; x++)
	for(int y = 0; y + m - 1 < n; y++) {
		bool ok = 1;
		for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			ok &= s[x + i][y + j] == t[i][j];
		if(ok) {
			cout << "Yes";
			exit(0);
		}
	}
	cout<<"No";
}


