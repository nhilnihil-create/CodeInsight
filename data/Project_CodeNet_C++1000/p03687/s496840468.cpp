#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;

    map<char, int> M;
    rep(i, s.length()) M[s[i]]++;

    int cnt1 = MOD;
    for (auto m : M)
    {
        char c = m.first;
        int cnt2 = 0, cnt3 = 0;
        rep(i, s.length())
        {
            if (s[i] == c)
            {
                cnt2 = max(cnt2, cnt3);
                cnt3 = 0;
            }
            else
            {
                cnt3++;
            }
        }
        cnt2 = max(cnt2, cnt3);
        cnt1 = min(cnt1, cnt2);
    }

    cout << cnt1 << endl;
}