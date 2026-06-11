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
    ll result = atoll(s.c_str());
    int k = 0;
    FOR(i, 1, pow(2, s.size() - 1) - 1){
        a = s[0];
        REP(j, s.size()-1){
            k++;
            if (i & (1 << j)){
                result += atoll(a.c_str());
                a = "";
            }
            a += s[k];
        }
        k = 0;
        result += atoll(a.c_str());
        a = "";
    }
    cout << result;
}