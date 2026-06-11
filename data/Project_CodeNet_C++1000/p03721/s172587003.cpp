#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n, k, i;
    cin >> n >> k;
    vector<pair<int, int>> ary(n);
    for (i = 0; i < n; i++)
    {
        cin >> ary.at(i).first >> ary.at(i).second;
    }
    sort(ary.begin(), ary.end());
    int cnt = 0;
    while (k > 0)
    {
        if (k > ary.at(cnt).second)
        {
            k -= ary.at(cnt).second;
            cnt++;
        }
        else
        {
            k = 0;
        }
    }
    cout << ary.at(cnt).first << endl;
}