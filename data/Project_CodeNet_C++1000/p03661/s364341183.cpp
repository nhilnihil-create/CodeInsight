#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cstring>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define vi vector < int >
#define vll vector < long long >
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))
#define fname "searching"

const int inf = (int)1e9;
const ll INF = (ll)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;

int n;
ll a[200200];
ll s;

ll solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        s += a[i];
    }

    ll x = a[0];
    ll ans = abs(2ll * x - s);
    for(int i = 1; i < n; ++i){
        ans = min(ans, abs(2ll * x - s));
        x += a[i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << "\n";
    
    return 0;
}
