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
 
 
typedef tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;
    
    //cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for(i = 0; i < n; i++){
            cin >> v[i];
        }
        indexed_set s;
        ll time = 0;
        s.insert({0, ++time});
        ll sum = 0;
        ll ans = 0;
        //s.insert({2, 5});
        for(i = 0; i < n; i++){
            sum += v[i];
            //cout <<"#"<< s.size() << endl;
            //for(auto u : s){
            //    cout << u.ff << " " << u.ss << endl;
            //}
            ll pos = s.order_of_key({sum - k * (i + 1) + 1, 0});
            pos--;
            ll minval = (*s.find_by_order(0)).ff;
            ll maxval = (*s.find_by_order(pos)).ff;
            if(maxval > sum - k * (i + 1)){
                pos--;
            }
            //cout << "####" << pos << endl;
            if(sum - k * (i + 1) >= minval)
                ans += (pos + 1);
            s.insert({sum - k * (i + 1), ++time});
            //cout <<"$$"<<ans << endl;
        }
        cout << ans;
    }
    return 0;
}