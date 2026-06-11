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
ll gcd(ll a , ll b){
	if(b == 0) return a;
	return gcd(b , a % b);	
}
ll lcm(ll a , ll b){
	ll g = gcd(a , b);
	ll lc = (a/g) * b;
	return lc;
}
vector< ll > a;
vector< ll > st;
int main()
{
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		ll x;
		cin >> x;
		st.push_back(x);
	}
	sort(st.begin(),st.end());
	for(int i = 0 ; i < (int)st.size() ; i++){
		if(st[i] == st[i+1]){
			a.push_back(st[i]);
			i++;
		}
	}
	if(a.size() < 2)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << a[a.size() - 1 ] * a[a.size() - 2] << endl;
	return 0;
} 


