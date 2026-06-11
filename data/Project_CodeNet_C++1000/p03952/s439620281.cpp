// by batr (TBhero.17)                      
// This will be Accepted!
 
#include <bits/stdc++.h>
 
#define jyldam ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pb push_back
#define mp make_pair
 
#define B begin()
#define E end()
#define sz size()
#define skip continue
#define all(x) (x).begin(), (x).end()
 
#define F first
#define S second          
 
#define st(x) st+=x
#define pli pair<long long, int>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;     
 
const int N = 1e6 + 17, M = N * 4, D = 2e3 + 17, mod = 1e9 + 7;
const ll INF = 1e17 + 17;
 
int tt = 1;
ll n, x;
ll a[N];
   
void solve () {               
	cin >> n >> x;
	if (x == 1 || x == 2 * n - 1) {
		cout << "No";
		return;
	}
    
    a[n] = x;
    ll g = x;

    for(int i = n + 1; i <= 2 * n - 1; i++){
   		a[i] = ++x;
   		x %= (2 * n - 1);
    }

    for(int i = 1; i <= n - 1; i++){
    	a[i] = ++x;
    	x %= (2 * n - 1);
    }        

    cout << "Yes\n";

    for(int i = 1; i <= 2 * n - 1; i++){
    	cout << a[i] << ' ';
    }
}   
		    
int main() {
		jyldam;
						                  
		while (tt--) {   
			solve();
		}
   	
		return 0;
}