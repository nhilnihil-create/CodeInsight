#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF 1e18
#define MOD 1e9 + 7

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main()
{
    int x;
    cin >> x;

    int ans = 0;
    int cnt = 0;
    for (int i = 1; cnt < x; i++)
    {
        cnt += i;
        ans++;
    }

    cout << ans << endl;

    return 0;
}