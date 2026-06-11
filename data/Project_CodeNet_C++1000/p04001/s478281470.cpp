#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;

    ll res = 0, pos = 0, ans = 0;
    for (int bit = 0; bit < (1<<S.length()-1); ++bit) {
        //cout << bitset<3>(bit) << endl;

        res = 0, pos = 0;
        REP(i, S.length()-1) {
            pos += int(S[i] - '0');
            if (bit & (1<<i)) {
                res += pos;
                pos = 0;
            }
            else{
                pos = pos * 10;
            }
            //cout << pos << endl;
        }
        pos += int(S[S.length()-1] - '0');
        ans += res + pos;
        //cout << res + pos << endl;
    }
    cout << ans << endl;
}