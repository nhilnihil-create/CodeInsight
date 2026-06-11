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
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1000000007;

int main()
{
    int N;
    string s, t;
    cin >> N >> s >> t;
    string s1, t1;
    for (int i = N; i >= 0; i--)
    {
        s1 = s.substr(N - i, i);
        t1 = t.substr(0, i);
        if (s1 == t1)
        {
            cout << 2 * N - i << endl;
            return 0;
        }
    }
}