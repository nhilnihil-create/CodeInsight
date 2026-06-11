#include <bits/stdc++.h>                                           

#define int long long	
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);                                          
#define forev(i, b, a) for(int i = (b); i >= (a); --i)	    
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define all(x) x.bg, x.en                                                                    
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define rbg rbegin()
#define bg begin()
#define en end()
#define s second
#define f first                                               
	
   
using namespace std;                  
   
   
typedef pair < unsigned long long, unsigned long long > puu;
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;
typedef unsigned long long ull;         
typedef long double ldb; 
typedef long long ll;  
typedef double db;                            
						               
	
const int inf = 1e9, N = 1e5 + 11, mod = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
const db eps = 1e-5, pi = 3.14159265359; 
const puu base = mp(1e9 + 7, 1e9 + 9);                                      
const ll INF = 1e18;             

int n, a[N], d[N], sum;

main () {     
	cin >> n;
	forn (i, 1, n) {
		cin >> a[i];
		sum += a[i];	
	}

	if (sum %  (n*(n + 1) / 2)) {
		cout << "NO";
		return 0;
	}

	int k = sum / (n*(n + 1) / 2);

	forn (i, 1, n - 1)
		d[i] = a[i + 1] - a[i];

	forn (i, 1, n - 1) 
		if (((k - d[i]) % n) || k < d[i]) {
			cout << "NO";
			return 0;
		}

	cout << "YES";
	return 0;
}