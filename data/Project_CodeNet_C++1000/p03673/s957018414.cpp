// https://atcoder.jp/contests/abc066/tasks/arc077_a
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
    cin >> N;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    int idx = N - 1;
    vector<int> res;
    while(idx >= 0)
    {
        res.push_back(a[idx]);
        idx -= 2;
    }
    if (idx == -2) idx = 1;
    else if (idx == -1) idx = 0;
    while(idx < N - 1)
    {
        res.push_back(a[idx]);
        idx += 2;
    }
    for (const auto& num : res)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
