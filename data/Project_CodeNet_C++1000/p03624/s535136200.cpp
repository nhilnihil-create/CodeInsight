//
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
    string S;
    cin >> S;
    vector<int> cnts(26, 0);
    for (int i = 0; i < S.size(); ++i)
    {
        ++cnts[S[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i)
    {
        if (cnts[i] == 0)
        {
            cout << char('a' + i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}
