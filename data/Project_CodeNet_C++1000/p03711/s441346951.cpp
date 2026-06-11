#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    
    set<int> x = {1, 3, 5, 7, 8, 10, 12}, y={4, 6, 9, 11};
    int a, b;   cin >> a >> b;
    string ans="No";
    if(x.find(a)!=x.end() && x.find(b)!=x.end()) ans = "Yes";
    else if(y.find(a)!=y.end() && y.find(b)!=y.end()) ans = "Yes";

    cout << ans << endl;

}