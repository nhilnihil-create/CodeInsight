#include<iostream>
#include<unordered_map>
#include<bitset>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<ctype.h>
#include<unordered_set>
#include<string>
#include<iomanip>
#include<queue>
#include<limits>
#include<map>
#include<stack>
#include<iterator>
#include<cstring>

#include<deque>
#define pi 3.141592653589793238
#include<chrono>

#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
#define mt make_tuple
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f0 get<0>
#define f1 get<1>
#define f2 get<2>

using namespace std;
ll n;
ll ncr(ll n, ll r)
{
    ll i, ans = 1, k = 0;
    if (r == 0)
        return 1;
    else if (n < r)
        return 0;
    for (i = n; i >= n - r + 1; i--)
    {
        ans *= i;
        ans /= n - i + 1;
    }


    return ans;

}


void max_heapify(int a[100], int i)
{
    int l, r, largest = i;
    l = 2 * i + 1;
    r = 2 * i + 2;
    if (l<n && a[l]>a[i])
        largest = l;
    if (r<n && a[r]>a[l])
        largest = r;
    if (largest != i)
    {
        int k;
        k = a[i];
        a[i] = a[largest];
        a[largest] = k;
        max_heapify(a, largest);
    }

}
int power(ll x, ll y, ll p)
{
    int res = 1;
    x = x % p;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;


        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

bool square(ll n)
{
    double x;
    x = sqrt(n);
    if (x == floor(x))
        return true;
    else return false;
}


bool prime(ll n)
{
    ll i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll modi(ll a, ll m)
{
    return power(a, m - 2, m);

}
void kmp(string s, ll p[]) {
    int n = (int)s.length();
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }

}
void zfunc(string s, ll z[]) {

    ll n = (ll)s.length();
    z[0] = 0;
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }


}
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<ll>() ((((ll)p.first) << 32) | ((ll)p.second));
    }
};

bool palin(string s) {
    ll i, n;
    n = s.length();
    for (i = 0; i <= n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}
ll sum(ll n) {
    ll i;
    i = n;
    ll sum = 0;
    while (i > 0) {
        sum += i % 10;
        i = i / 10;
    }
    return sum;
}

ll nCr(ll n, ll r, ll p, ll fac[])
{

    if (r == 0)
        return 1;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % p;

    return (fac[n] * modi(fac[r], p) % p *
        modi(fac[n - r], p) % p) % p;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll mod(string num, ll a)
{

    ll res = 0;


    for (ll i = 0; i < num.length(); i++)
        res = (res * 10 + (ll)num[i] - '0') % a;

    return res;
}
void printbinary(ll n,ll m)
{
    
    ll binaryNum[60];

   
    int i = 0;
    while (n > 0) {

        
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (ll j = m - 1; j >= i; j--) {
        cout << 0;
    }
    for (ll j = i - 1; j >= 0; j--)
        cout << binaryNum[j] ;
    cout << endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll parent[1000], sizer[1000];
ll findset(ll a) {
    if (a == parent[a]) {
        return a;
    }
    parent[a] = findset(parent[a]);
    return parent[a];
}

void unionset(ll a, ll b) {
    a = findset(a);
    b = findset(b);
    if (sizer[a] < sizer[b]) {
        swap(a, b);
    }
    sizer[b] += sizer[a];
    parent[b] = a;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct fenwick {
    vector<ll> bit;
    ll n;
    fenwick(ll n, vector<ll> v) {
        this->n = n;
        bit.assign(n, 0);
        for (ll it = 0; it < n; it++) {
            add(it, v[it]);
        }
    }

    ll sum(ll idx) {
        if (idx < 0)
            return 0;
        ll ret = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            ret += bit[idx];
        }
        return ret;
    }
    void add(ll idx, ll x) {
        for (; idx < n; idx = idx | (idx + 1)) {
            bit[idx] += x;
            bit[idx] = max(0LL, bit[idx]);
        }
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll T = 1, i, j;

    //cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll ans = INF;
        for (i = 0; i < pow(2, n); i++) {
            bitset<15> b = i;
            ll count = b.count();
            if (count != k) {
                continue;
            }
            ll lastheight = 0;
            ll cost = 0;
            for (j = 0; j < n; j++) {
                if (b[j] == 1) {
                    if (lastheight < v[j]) {
                        lastheight = v[j];
                    }
                    else {
                        cost += lastheight + 1 - v[j];
                        lastheight += 1;
                    }
                }
                else {
                    lastheight = max(lastheight, v[j]);
                }
            }
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }

    return 0;
}
