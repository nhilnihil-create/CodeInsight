#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
#define sz(x)       int(x.size())
#define int         int64_t

using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 1;
const int M = 2e5 + 1;
const ll inf = (ll)1e18;

int p[11];

bool get(int x) {
    cout << "? " << x << '\n';
    char c; cin >> c;
    return c == 'Y';
}

void answer(int x) {cout << "! " << x << '\n'; exit(0);}

int getLeng() {
   int low = 1, mid, high = 10; bool ans;
   while(low <= high) {
       mid = (low + high) >> 1;
       ans = get(p[mid - 1]);
       if(ans) low = mid + 1;
       else high = mid - 1;
   }
   return high;
}

int L, low, high, mid, n;

void check() {
    if(!get(p[10])) return;
    int low = 1, high = 10, mid; bool ans;
    while(low <= high) {
        mid = (low + high) >> 1;
        if(get(2ll * p[mid - 1])) high = mid - 1;
        else low = mid + 1;
    }
    answer(p[high]);
}

int32_t main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0), cout.tie(0);
//    #define Task        "test"
//    if(fopen(Task".inp", "r")) {
//        freopen(Task".inp", "r", stdin);
//        freopen(Task".out", "w", stdout);
//    }
    p[0] = 1;
    for(int i = 1; i <= 10; ++i) p[i] = 1ll * p[i - 1] * 10;
    check(); L = getLeng(); n = 0;
    for(int i = 1; i < L; ++i) {
        low = i == 1? 1: 0; high = 9;
        while(low <= high) {
            mid = low + high >> 1;
            if(get(n * 10 + mid)) low = mid + 1;
            else high = mid - 1;
        }
        n = n * 10 + high;
    }
    low = L == 1? 1: 0; high = 9;
    while(low <= high) {
        mid = low + high >> 1;
        if(get((ll)(1ll * n * 100 + mid * 10))) high = mid - 1;
        else low = mid + 1;
    }
    n = n * 10 + low;
    answer(n);
}
