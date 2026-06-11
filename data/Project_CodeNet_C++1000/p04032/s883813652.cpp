#include <bits/stdc++.h>

using namespace std;
#define sqr(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define GCD(a, b) __gcd(a, b)
#define LCM(a, b) ((a)*(b)/GCD(a,b))
#define MP make_pair
#define n1 first
#define n2 second
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define SI set<int>
#define SL set<ll>
#define MS multiset
#define MSI multiset<int>
#define MSLL multiset<ll>
#define PB push_back
#define PF push_front
#define VI vector<int>
#define VPI vector<pair<int,int>>
#define VLL vector<ll>
#define SZ(x) ((int)x.size())

typedef long long ll;

typedef unsigned long long ull;
typedef long double ld;
typedef double db;
const int INF = 1e9;
const int MOD = 1000000007;
const int N = 202055;
const int M = 1211;

void solve() {
    string s;
    cin >> s;

    int n = SZ(s);

    for (int i = 0; i < n; i++){
        for (int j = i+1; j <= i+2; j++){
            if (s[i] == s[j]){
                cout << i+1 << ' ' << j+1;
                return;
            }
        }
    }

    cout << -1 << ' ' << -1;

}

int main() {
    ios_base::sync_with_stdio(false);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T = 1;
    //cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}