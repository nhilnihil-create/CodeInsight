#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    string s;
    cin >> s;
    int n = s.size() - 1;
    ll ans = 0;
    for (int i = 0; i < pow(2, n); i++)
    {
        vector<int> bt;
        int cp = i;
        for (int j = 0; j < n; j++)
        {
            bt.push_back(cp % 2);
            cp /= 2;
        }
        string num;
        num.push_back(s[0]);
        for (int k = 0; k < n; k++)
        {
            if (bt[k] == 0)
            {
                num.push_back(s[k + 1]);
            }
            else
            {
                ans += stoll(num);
                num = s[k + 1];
            }
        }
        ans += stoll(num);
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
