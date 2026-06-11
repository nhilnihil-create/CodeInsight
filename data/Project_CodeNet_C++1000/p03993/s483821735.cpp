#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <iomanip>
#include <vector>
#include <functional>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(begin, i, end) for (int i = begin; i < (int)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    map<P, int> mp;
    int a;
    rep(0, i, N)
    {
        cin >> a;
        a--;
        mp[make_pair(min(i, a), max(i, a))]++;
    }
    int ans = 0;
    for (auto m : mp)
    {
        ans += m.second / 2;
    }
    cout << ans << endl;
}