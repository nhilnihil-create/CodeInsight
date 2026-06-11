#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repm(i, a, n) for (ll i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define mod (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<vector<int>>
#define vllll vector<vector<ll>>
#define ALL(a) (a).begin(), (a).end()

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void print(bool f)
{
    cout << (f ? "Yes" : "No") << endl;
}

void Print(bool f)
{
    cout << (f ? "YES" : "NO") << endl;
}

int main(void)
{
    string s;
    cin >> s;

    set<char> st;
    for (auto x : s)
        st.insert(x);
    if (st.size() == 1)
        return cout << 0 << endl, 0;
    ll ans = INF;
    for (auto c : st)
    {
        string t = s;
        ll cnt = 0;
        while (1)
        {
            string tmp;
            set<char> tt;
            rep(i, 0, t.size() - 1)
            {
                tmp += (t[i] == c || t[i + 1] == c ? c : t[i]);
                tt.insert(t[i] == c || t[i + 1] == c ? c : t[i]);
            }
            cnt++;
            if (tt.size() == 1)
                break;
            t = tmp;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}