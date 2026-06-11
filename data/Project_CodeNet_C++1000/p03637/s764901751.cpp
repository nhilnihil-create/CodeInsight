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

map< int , int > mp[nax];
int main()
{
	int n;
	cin >> n;
	int cnt = 0 , cnt2 = 0;
	for(int i = 0 ; i < n ;i++){
		int x;
		cin >> x;
		if(x % 4 == 0)
			cnt++;
		else if(x % 2 == 0)
			cnt2++;
	}
	int rem = n - cnt - cnt2 + cnt2%2;
	if(cnt >= rem - 1)
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
	return 0;
} 


