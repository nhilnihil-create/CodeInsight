#include <bits/stdc++.h>
#include <math.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ept 1e-9

using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int mod = 1e9 + 7;
ll ps[200010], as[200010];
vector<int>pos;
void cut(ll &val, int pos1, int pos2)
{
    if (pos1 > pos2) return;
    val -= as[pos2] - as[pos1 - 1];
}

int main()
{
    int n = read();
    int val = read();
    ps[1] = val;
    as[1] = val;
    rep(i, 2, n)
    {
        int val;
        char op;
        cin >> op;
        scanf("%d", &val);
        if (op == '+') ps[i] = ps[i - 1] + val;
       	else ps[i] = ps[i - 1] - val, pos.push_back(i);
        as[i] = as[i - 1] + val;
    }
    ll ans = ps[n];
    int nn = pos.size() - 2;
    rep(i, 0, nn)
    {
        int p1 = pos[i], p2 = pos[i + 1];
        ll tans = as[n] - as[p2 - 1];
        tans += ps[p1];
        cut(tans, p1 + 1, p2 - 1);
        ans = max(ans, tans);
    }
    cout << ans << endl;
    return 0;
}
