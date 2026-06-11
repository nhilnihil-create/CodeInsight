#include <bits/stdc++.h>
 
#define pb push_back
#define ll long long
#define F first
#define S second
#define ld long double
#define fa fflush(stdout); 
#define mp make_pair
using namespace std;
void data() {
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
} 
const int N = 1e6 + 100;
const ll mod = 998244353;
const ll mod2 = 1e9 + 7;
 
ll mul(ll a, ll b) {
	return (a * b) % mod2;
}
ll ans = 1;
ll ans2 = 1;
int main () 
{
    data();     
    int n, m;
    cin >> n >> m;
    int all = n + m;
    int n2 = n;
    int m2 = m;
    for (int i = 1; i <= all; i++)
    {
    	if (i % 2)
    	{
    		ans = mul(ans, n);
    		n--;
    	}
    	else {
    		ans = mul(ans, m);
    		m--;
    	}
    	ans = max(ans, 0LL);
    	if (i % 2)
    	{
    		ans2 = mul(ans2, m2);
    		m2--;
    	}
    	else {
    		ans2 = mul(ans2, n2);
    		n2--;
    	}
    	ans2 = max(ans2, 0LL);
    	ans %= mod2;
    	ans2 %= mod2;
    }
  //  cout << ans << " " << ans2 << '\n';
    cout << (ans + ans2) % mod2;
}
//Timus:295965SY              