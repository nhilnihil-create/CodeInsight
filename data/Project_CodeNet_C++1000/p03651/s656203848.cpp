// https://atcoder.jp/contests/agc018/tasks/agc018_a
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

template <class T>
T calcgcd(T x, T y)
{
    if (x < y)
    {
        std::swap(x, y); //小さい方をyとする
    }
    T r = x % y;
    while( r != 0 )
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int maxval = -1;
    vector<int> A(N);
    REP(i, N) 
    {
        cin >> A[i];
        maxval = max(maxval, A[i]);
    }
    int c = A[0];
    for (int i = 1; i < N; ++i)
    {
        c = calcgcd(c, A[i]);
    }
    if (K <= maxval && K % c == 0)
    {
        cout << "POSSIBLE\n";
        return 0;
    }

    cout << "IMPOSSIBLE\n";
    
    return 0;
}