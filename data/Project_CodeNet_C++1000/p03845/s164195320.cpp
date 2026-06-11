// https://atcoder.jp/contests/abc050/tasks/abc050_b
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
    vector<int> T(N);
    int sum = 0;
    REP(i, N) 
    {
        cin >> T[i];
        sum += T[i];
    }
    int M;
    cin >> M;
    vector<int> P(M), X(M);
    REP(i, M)
    {
        cin >> P[i] >> X[i];
        --P[i];
    }

    vector<int> res(M);
    REP(i, M)
    {
        int idx = P[i];
        res[i] = sum - T[idx] + X[i];
    }

    REP(i, M)
    {
        cout << res[i] << endl;
    }
    return 0;
}
