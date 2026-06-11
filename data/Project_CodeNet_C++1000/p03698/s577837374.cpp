// https://atcoder.jp/contests/abc063/tasks/abc063_b
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <stack>
#include <queue>
#include <iomanip>
#include <set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    string S;
    cin >> S;
    vector<int> cnts(26, 0);
    REP(i, S.size())
    {
        ++cnts[S[i] - 'a'];
    }
    REP(i, 26)
    {
        if (cnts[i] > 1)
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}
