// https://atcoder.jp/contests/abc052/tasks/abc052_b
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int N;
    string S;
    cin >> N >> S;
    int x = 0, ans = 0;
    REP(i, N)
    {
        if (S[i] == 'I')
        {
            ++x;
        }
        else
        {
            --x;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}
