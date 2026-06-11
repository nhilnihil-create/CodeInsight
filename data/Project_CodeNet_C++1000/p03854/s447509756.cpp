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
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main()
{
    string S;
    cin >> S;
    std::reverse(S.begin(), S.end());
    string rd = "maerd", rder = "remaerd", re = "esare", rer = "resare";
    int i = 0;
    int n = S.size();
    while (i < n)
    {
        if (i + 6 < n && S.substr(i, 7).compare(rder) == 0)
        {
            i += 7;
        }
        else if (i + 5 < n && S.substr(i, 6).compare(rer) == 0)
        {
            i += 6;
        }
        else if (i + 4 < n && (S.substr(i, 5).compare(rd) == 0 || S.substr(i, 5).compare(re) == 0))
        {
             i += 5;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
