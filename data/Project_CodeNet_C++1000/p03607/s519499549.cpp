#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    map<string, int> a;
    rep(i, n)
    {
        string s;
        cin >> s;
        a[s]++;
    }
    int count = 0;
    for (auto p : a)
    {
        if (p.second % 2 == 1)
            count++;
    }
    cout << count << endl;
    return 0;
}