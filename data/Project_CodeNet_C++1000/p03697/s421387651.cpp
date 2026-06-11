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
int count(ll x){
	int cnt = 0;
	while(x != 0){
		cnt++;
		x /= 10;
	}
	return cnt;
}
char a[55][55] , b[55][55];
int main()
{
	int a , b;
  	cin >> a >> b;
  	if(a + b >= 10)
      cout << "error" << endl;
 	else
      cout << a + b << endl;
	return 0;
} 

