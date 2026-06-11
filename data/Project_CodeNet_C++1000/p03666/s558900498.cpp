#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
  
void solve() {
	ll n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	
	for(int m = 0; m < n; m++) {
		if(a - b >= -d * (m) + c * (n - m - 1) && a - b <= d * (n - m - 1) - c * m) {
			cout << "YES" << endl;
			return;
		}
	}
	
	cout << "NO" << endl;
}
 
int main(){
#define MULTITEST 0
#if MULTITEST   
 
    CASET {
        solve();
    }
    
#else
 
    solve();
    
#endif
 
    return 0;
}