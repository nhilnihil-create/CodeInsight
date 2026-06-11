// https://atcoder.jp/contests/abc052/tasks/abc052_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int curr = 0;
    int ans = curr;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I')
        {
            curr++;
        }
        else
        {
            curr--;
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}
