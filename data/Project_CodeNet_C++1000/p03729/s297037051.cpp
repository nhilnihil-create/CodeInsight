#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
int main()
{
	string a , b , c;
	cin >> a >> b >> c;
	if(a[a.size()-1] == b[0] && b[b.size()-1] == c[0])
		cout << "YES" << endl;
	else 
		cout << "NO" << endl;
	return 0;
} 


