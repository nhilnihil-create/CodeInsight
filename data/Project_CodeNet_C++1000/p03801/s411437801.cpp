#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define repr(i, a, n) for (ll i = n - 1; (ll)a <= i; i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 + 99);
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T>
T mpow(T a, T n)
{
    T res = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

//cin.tie(0);ios::sync_with_stdio(false);

signed main()
{
    int n, nowmx = 0;
    cin >> n;
    vector<ll> v(n), ans(n, 0);
    vector<int> mx(n, 0);
    rep(i, 0, n)
    {
        cin >> v[i];
        if (nowmx < v[i])
        {
            mx[i] = i;
            nowmx = v[i];
        }
        else
        {
            mx[i] = mx[i - 1];
        }
    }

    int mxi = mx[n - 1], ind = n - 1, nmxi = mxi, cnt = 0, pmxi=0;
    priority_queue<ll> q;
    while (1)
    {

        if (0 < mxi)
        {
            nmxi = mx[mxi - 1];
        }
        else
        {
            while (mxi < ind)
            {
                ans[0]+=v[ind];
                ind--;
            }
            while (!q.empty())
            {
                ans[0] += q.top();
                q.pop();
            }
            ans[0] += v[0];
            ans[0] += (v[mxi]) * cnt;
            break;
        }

        ans[mxi] += (v[mxi] - v[nmxi]) * cnt;

        while (mxi < ind)
        {
            if (v[nmxi] <= v[ind])
            {
                ans[mxi] += v[ind] - v[nmxi];
                cnt++;
            }
            else
            {
                q.push(v[ind]);
            }
            ind--;
        }
        ind--;

        while (!q.empty() && q.top() > v[nmxi])
        {
            ans[mxi] += q.top() - v[nmxi];
            q.pop();
            cnt++;
        }

        ans[mxi] += v[mxi] - v[nmxi];
        cnt++;
        pmxi = mxi;
        mxi = nmxi;
    }

    rep(i, 0, n) cout << ans[i] << endl;
}