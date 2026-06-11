#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

vector<ll> vec;

vector<ll> divisor(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    string S;
    cin >> N;

    vec = divisor(N);

    ll ans = LLINF;

    REP(i,vec.size()){
        ll tmp = N / vec.at(i);
        double tmp1 = log10(vec.at(i));
        double tmp2 = log10(tmp);

        ll tmp3 = (ll)(max(tmp1, tmp2));

        ans = min(ans, tmp3+1);
    }
    cout << ans << endl;
}
