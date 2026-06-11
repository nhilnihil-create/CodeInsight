#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

string concat(string s, string t)
{
    int n = s.size();

    for (int i = n; i >= 1; --i) {
        string ss = s.substr(n - i, i);
        string tt = t.substr(0, i);

        if (ss == tt) {
            return s.substr(0, n-i) + ss + t.substr(i, n-i);
        }
    }

    return s + t;
}

int main()
{
    int N;
    cin >> N;

    string s, t;
    cin >> s;
    cin >> t;

    cout << concat(s, t).size() << endl;

    return 0;
}
