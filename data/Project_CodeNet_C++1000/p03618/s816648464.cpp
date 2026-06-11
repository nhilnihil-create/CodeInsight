#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define vec vector
#define endl '\n'
#define ss second
#define ff first

#define watch(x) cout<<#x<<" is "<<x<<endl;

#define MAX 200100
#define MOD 1000000007
#define INF 2100000000

using namespace std;

string s;
map < char, int > m;

int32_t main ()
{
    ios_base::sync_with_stdio ( 0 );
    cin.tie ( 0 ); cout.tie ( 0 );
    
	cin >> s;
	int n = s.size();

	for ( int i = 0; i < n; ++ i )
		m[s[i]] ++;

	int ans = 1+n*(n-1)/2;

	for ( auto i: m )
		ans -= i.ss*(i.ss-1)/2;

	cout << ans << endl;

    return 0;
}
