// https://atcoder.jp/contests/abc061/tasks/abc061_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> ctr(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ctr[--a]++;
        ctr[--b]++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ctr[i] << endl;
    }
    return 0;
}
