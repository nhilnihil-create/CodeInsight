#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>
 
#include<deque>
#define pi 3.141592653589793238
#include<chrono>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        
        string s, t;
        cin >> s >> t;
        ll n = s.size();
        ll m = t.size();
        vector<vector<ll>> prefs(n + 1, vector<ll>(26)), preft(m + 1, vector<ll>(26));
        for(i = 0; i < n; i++){
            for(j = 0; j < 26; j++){
                prefs[i + 1][j] = prefs[i][j];
            }
            prefs[i + 1][s[i] - 'A']++;
        }
        for(i = 0 ; i < m; i++){
            for(j = 0; j < 26; j++){
                preft[i + 1][j] = preft[i][j];
            }
            preft[i + 1][t[i] - 'A']++;
        }
        ll q;
        cin >> q;
        while(q--){
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            ll c1, c2;
            c1 = prefs[b][0] - prefs[a - 1][0] + 2 * (prefs[b][1] - prefs[a - 1][1]);
            c2 = preft[d][0] - preft[c - 1][0] + 2 * (preft[d][1] - preft[c - 1][1]);
            ll val = abs(c1 - c2);
            //cout << c1 << " " << c2 << endl;
            if(val % 3 == 0){
                cout << "YES\n";
            } 
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}