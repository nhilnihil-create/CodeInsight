#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
#define f first
#define s second
#define CS ios_base::sync_with_stdio(0);cin.tie(0);
#define PI acos(-1)
typedef long long ll;
typedef long double ld;
const int mod = ( int ) 1e9 + 7;
const int mod2 = ( int ) 1e9 + 9;
const ll inf = 1e18 + 100;
const int INF = 2000000000;
const int N = 1e6 + 100;
const long double EPS = 1e-9;
typedef complex < double > pt;



int main()
{
	CS;

	int h, w, d;
	cin >> h >> w >> d;
	for(int i = 0; i < h; i++)
	{
		int x = 550 - i;
		for( int j = i ; j < w + i ; j++, x++ )
		{
			if((x / d) % 2 == 0 && (j / d) % 2 == 0 )
				cout << 'Y';
			else if((x / d) % 2 == 1 && (j / d) % 2 == 0 )
				cout << 'G';
			else if((x / d) % 2 == 0 && (j / d) % 2 == 1 )
				cout << 'R';
			else if((x / d) % 2 == 1 && (j / d) % 2 == 1 )
				cout << 'B';
			if( j == w + i - 1 )
				cout << endl;
		}
	}

	return 0;
}