#include <bits/stdc++.h>
using namespace std;

#define REP(i, m, n) for (int i = (m); i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
typedef long long ll;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

ll modpow(ll a, ll p)
{
    if (p == 0)
        return 1;
    if (!(p % 2))
    {
        ll halfP = p / 2;
        ll half = modpow(a, halfP);
        return half * half % mod;
    }
    else
    {
        return a * modpow(a, p - 1) % mod;
    }
}

ll comb(int a, int b)
{
    if (b > a - b)
        return comb(a, a - b);
    ll ansMul = 1;
    ll ansDiv = 1;
    for (int i = 0; i < b; i++)
    {
        ansMul *= a - i;
        ansDiv *= i + 1;
        ansMul %= mod;
        ansDiv %= mod;
    }
    ll ans = ansMul * modpow(ansDiv, mod - 2) % mod;
    return ans;
}

/*
int num = 200010;
vector<ll> fact(num), ifact(num);
fact[0] = 1;
fact[1] = 1;
for (int i = 2; i < num; i++) {
    fact[i] = fact[i-1] * i;
    fact[i] %= mod;
}
for (int i = 0; i < num; i++) {
    ifact[i] = modpow(ifact[i], mod-2);
    ifact[i] %= mod;
}
*/

int main() {
    int N; cin >> N;
    string s; cin >> s;
    vector<string> pos{
        "SS", "SW", "WS", "WW"
    };
    rep(k, 4) {
        string t = pos[k];
        rep(i, N) {
            if (i == N-1) s += s[0];
            if (t[i+1] == 'S') {
                if (t[i] == 'S' && s[i+1] == 'o') t += 'S';
                if (t[i] == 'S' && s[i+1] == 'x') t += 'W';
                if (t[i] == 'W' && s[i+1] == 'o') t += 'W';
                if (t[i] == 'W' && s[i+1] == 'x') t += 'S';
            }
            else if (t[i+1] == 'W') {
                if (t[i] == 'S' && s[i+1] == 'o') t += 'W';
                if (t[i] == 'S' && s[i+1] == 'x') t += 'S';
                if (t[i] == 'W' && s[i+1] == 'o') t += 'S';
                if (t[i] == 'W' && s[i+1] == 'x') t += 'W';
            }
        }
        if (t[N] == t[0] && t[N+1] == t[1]) {
            cout << t.substr(0, N) << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
