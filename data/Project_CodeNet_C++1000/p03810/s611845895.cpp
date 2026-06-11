
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

/*************************************************************************/

bool solve(int n, VI &a) {
    if (n == 1) {
        return false;
    }
    
    int sum = 0;
    FOR(i,0,n-1) {
        sum = (sum + a[i]) % 2;
    }
    
    if (1 - sum == n % 2) {
        return true;
    }
    
    bool found = false;
    FOR(i,0,n-1) if (a[i] % 2 && a[i] > 1) {
        found = true;
        a[i]--;
        
        break;
    }
    
    if (!found) {
        return false;
    }
    
    int gcd = 0;
    FOR(i,0,n-1) {
        gcd = __gcd(gcd, a[i]);
    }
    
    FOR(i,0,n-1) {
        a[i] /= gcd;
    }
    
    return !solve(n, a);
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    VI a(n);
    FOR(i,0,n-1) {
        cin >> a[i];
    }
    
    cout << (solve(n, a) ? "First" : "Second");

    return 0;
}

/*************************************************************************/
