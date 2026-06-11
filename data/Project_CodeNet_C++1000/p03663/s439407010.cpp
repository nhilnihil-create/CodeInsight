/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

ll N = 2;

bool ok(ll n) {
    if (n <= N) {
        if (to_string(n) <= to_string(N)) return 1;
        return 0;
    }
    if (to_string(n) > to_string(N)) return 1;
    return 0;
}

int query(ll mid) {
    cout << "? " << mid << endl;
    char ans; cin >> ans;
    if (ans == 'Y') return 1;
    return 0;
}

ll po10(ll z) {
    ll ans = 1;
    F0R(i,z) ans *= 10;
    return ans;
}

void get() {
    ll lo = 1e10, hi = (1e11)-1; 
    while (lo < hi) {
        ll mid = (lo+hi)/2;
        
        // find first which gives yes
        if (query(mid)) hi = mid;
        else lo = mid+1;
    }
    
    while (lo % 10 == 0) lo /= 10;
    ll p = 1;
    while (10*p <= lo) p *= 10;
    
    ll lo1 = 0, hi1 = 9;
    
    while (p*po10(hi1) > 1e18) hi1--;
    
    while (lo1 < hi1) {
        if (lo != 1) {
            ll mid = (lo1+hi1+1)/2;
            if (query(p*po10(mid))) lo1 = mid;
            else hi1 = mid-1;
        } else {
            ll mid = (lo1+hi1)/2;
            if (query((10*p-1)*po10(mid))) hi1 = mid;
            else lo1 = mid+1;
        }
    }
    
    cout << "! " << lo*po10(lo1) << endl;
}

int main() {
    get();
}