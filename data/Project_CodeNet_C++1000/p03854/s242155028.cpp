#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chmax(T &u, const T z)
{
    if (u < z)
    {
        u = z;
        return true;
    }
    else
        return false;
}
template <typename T>
bool chmin(T &u, const T z)
{
    if (u > z)
    {
        u = z;
        return true;
    }
    else
        return false;
}
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
typedef pair<ll, ll> P;
const ll INF = 1LL << 60;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

int main()
{
    string a[] = {"maerd", "remaerd", "esare", "resare"};
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    bool hantei = false;
    rep(i, n)
    {
        hantei = false;
        rep(j, 4)
        {
            int k = a[j].size();
            string t = s.substr(i, k);
            //cout << a[j] << " " << t << endl;
            if (a[j] == t)
            {
                hantei = true;
                i += k - 1;
                break;
            }
        }
        if (hantei == false)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
