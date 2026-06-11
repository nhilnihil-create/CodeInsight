#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    string s;
    cin >> s;
    long long N = s.size();
    long long p_num = 0;
    rep(i, N)
    {
        if (s[i] == 'p')
            p_num++;
    }
    long long ans = N / 2 - p_num;
    cout << ans << endl;
    return 0;
}