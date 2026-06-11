#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define read(UIET) for(int i = 0; i < n; ++i) cin >> UIET[i]
#define out(UIET) for(int i = 0; i < n; ++i) cout << UIET[i]
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"
#define mod 1000000007
const int INF=(1LL<<60)-1;
bool isPerfectSquare(long double x) {   
    long double sr = sqrt(x); 
    return ((sr - floor(sr)) == 0); 
} 
int32_t main(){
    SPEED;
    int n;
    cin >> n;
    int x = 2;
    while(1){
        x *= 2;
        if(x > n){
            x /= 2;
            break;
        }
    }
    if(n == 1) cout << 1 ;
    else cout << x ;
}
