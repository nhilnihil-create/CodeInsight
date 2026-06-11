#include <bits/stdc++.h>

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define FORD(i, a, b) for (ll i = a; i >= (ll)(b); i--)

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

#define INF 1000000000000
#define MOD 1000000007
#define MAXR 100000

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    string a = "";
    ll result = 0;
    int k = 0;
    REP(i, pow(2, s.size() - 1)){
        REP(j, s.size()){
            a += s[k];
            if (i & (1 << j)){
                result += atoll(a.c_str());
                a = "";
            }
            k++;
        }
        k = 0;
        result += atoll(a.c_str());
        a = "";
    }
    cout << result;
}