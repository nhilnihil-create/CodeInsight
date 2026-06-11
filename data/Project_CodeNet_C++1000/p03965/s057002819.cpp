#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main()
{
    string s;
    cin >> s;

    vector<int> a(s.size() + 1);
    irep(i, s.size())
    {
        if (i == 0) {
            a[i] = 0;
        } else {
            a[i] = a[i - 1] + (s[i - 1] == 'g' ? 1 : -1);
        }
    }

    cout << a[s.size()] / 2 << endl;

    return 0;
}