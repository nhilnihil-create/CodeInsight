#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a, b, c, i, j, k, l, m, n, ans, tmp, hoge;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;
    string str;
    cin >> str;

    // cout << "a+b " << a + b << endl;
    // cout << "b " << b << endl;
    int countA = 0, countB = 0;
    rep(i, n)
    {
        // cout << "i " << i << " str " << str[i] << endl;
        // cout << "countA " << countA << endl;
        // cout << "countB " << countB << endl;
        if (str[i] == 'a')
        {
            if ((countA + countB) < (a + b))
            {
                countA++;
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
        else if (str[i] == 'b')
        {
            if (((countA + countB) < (a + b)) && countB < b)
            {
                countB++;
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
        else
            cout << "No" << endl;
        //cout << endl;
    }

    return 0;
}