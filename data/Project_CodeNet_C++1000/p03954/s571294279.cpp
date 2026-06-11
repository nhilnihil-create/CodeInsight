#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
const int maxn = 2e5 +5;
const int inf = 1e9 + 1;
const ll llinf = 1e18 + 5;
int n, a[maxn] , b[maxn];
bool check(int val){
    for(int i = 1 ; i <= 2 * n - 1 ; ++i){
        b[i] = (a[i] > val);
    }
    for(int i = 0 ; i < n - 1 ; ++i){
        if((b[n - i] && b[n - i - 1]) || (b[n + i] && b[n + i + 1]))return 1;
        if((!b[n - i] && !b[n - i - 1]) || (!b[n + i] && !b[n + i + 1]))return 0;
    }
    return b[1];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    if(fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1 ; i <= n * 2 - 1 ; ++i){
        cin >> a[i];
    }
    int l = 1;
    int h = n * 2 - 1;
    while(l <= h){
        int mid = l + h >> 1;
        if(check(mid))l = mid + 1;
        else h = mid - 1;
    }
    cout << l;
}

