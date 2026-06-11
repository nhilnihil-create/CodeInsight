#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    vector<string> Z(4);
    Z[0] = "dream";
    Z[1] = "dreamer";
    Z[2] = "erase";
    Z[3] = "eraser";
    rep(i, 4) reverse(Z[i].begin(), Z[i].end());

    int p = 0; //今参照してる場所
    while (1)
    {
        int no = 1;
        rep(i, 4)
        {
            if (s.substr(p, Z[i].length()) == Z[i])
            {
                p += Z[i].length();
                no = 0;
                break;
            }
        }
        if (no)
        {
            cout << "NO" << endl;
            return 0;
        }
        if (p == s.length())
        {
            cout << "YES" << endl;
            return 0;
        }
    }
}