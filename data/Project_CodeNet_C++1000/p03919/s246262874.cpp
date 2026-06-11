#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> P;
lli MOD = 1000000007;
int main()
{
    int w, h;
    string s;
    cin >> h >> w;
    rep(i, h) rep(j, w)
    {
        cin >> s;
        if (s == "snuke")
            cout << char(j + 'A') << i + 1 << endl;
    }
}
