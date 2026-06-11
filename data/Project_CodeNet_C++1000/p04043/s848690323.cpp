#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int main()
{
    vector<int> n(3);
    REP(i, 3)
    {
        cin >> n.at(i);
    }
    sort(n.begin(), n.end());
    if (n.at(0) == 5 && n.at(1) == 5 && n.at(2) == 7)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
