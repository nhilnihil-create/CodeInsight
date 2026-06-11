#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> w;
    rep(i, F)
    {
        rep(j, F)
        {
            int x = i * 100 * A + j * 100 * B;
            if (x <= F)
                w.push_back(x);
        }
    }

    vector<int> s;
    rep(i, F)
    {
        rep(j, F)
        {
            int y = i * C + j * D;
            if (y <= F)
                s.push_back(y);
        }
    }

    double n = 0;
    int sw_a = 100 * A;
    int s_a = 0;
    rep(i, w.size())
    {
        rep(j, s.size())
        {
            int sum = w[i] + s[j];
            if (sum > F || sum == 0)
                continue;
            if ((w[i] * E) / 100 >= s[j] && n < (100.0F * s[j] / sum))
            {
                n = 100.0F * s[j] / sum;
                sw_a = sum;
                s_a = s[j];
            }
        }
    }
    cout << sw_a << " " << s_a << endl;
    return 0;
}