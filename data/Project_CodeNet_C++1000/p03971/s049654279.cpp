#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// #define int long long

using namespace std;

signed main()
{
    int N, A, B;
    string s;

    cin >> N >> A >> B;
    cin >> s;
    int count = 0;
    int count_kaigai = 0;
    rep(i, N)
    {
        // cout << s[i] << count << endl;
        if (s[i] == 'a')
        {
            if (count < A + B)
            {
                cout << "Yes" << endl;
                count++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        if (s[i] == 'b')
        {
            if (count < A + B)
            {
                if (count_kaigai < B)
                {
                    cout << "Yes" << endl;
                    count++;
                    count_kaigai++;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
            else
            {
                cout << "No" << endl;
            }
        }
        if (s[i] == 'c')
        {
            cout << "No" << endl;
        }
    }
}