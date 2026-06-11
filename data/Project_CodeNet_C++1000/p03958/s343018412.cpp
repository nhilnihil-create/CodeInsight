#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e18;
const ll N =(100+5);
ll a[N];
void solve(){
    ll k,t;
    cin >> k >> t;
    for(int i = 1;i <= t;i++){
        cin >> a[i];
    }
    ll ans= 0;
    ll prev = -1;
    while(k){
        ll gg = -1;
        for(int j = 1;j<=t;j++){
            if(a[j] && prev != j && (gg == -1 || a[j] > a[gg])){
                gg = j;
            }
        }
        if(gg == -1) {
            gg = prev;
            ans++;
        }
        a[gg]--;
        prev = gg;
        k--;
    }
    cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    

 
     ll tt=1;   
    while(tt--){    
        solve();
    }    
}