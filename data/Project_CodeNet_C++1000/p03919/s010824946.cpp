#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;

    int tmp1 = 0;
    char tmp2 = 'A';
    rep (i, H) {
        rep (j, W) {
            string str;
            cin >> str;
            if (str == "snuke") {
                tmp1 += i+1;
                tmp2 += j;
                break;
            }
        }
    }

    cout << tmp2 << tmp1 << endl;


    return 0;
}
