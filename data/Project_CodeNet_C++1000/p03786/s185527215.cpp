// https://atcoder.jp/contests/agc011/tasks/agc011_b
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
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> S(N);
    S[0] = A[0];
    for (int i = 1; i < N; ++i)
    {
        S[i] = S[i - 1] + A[i];
    }
    int idx = -1;
    for (int i = N - 1; i >= 1; --i)
    {
        if (2 * S[i - 1] < A[i])
        {
            cout << N - i << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}