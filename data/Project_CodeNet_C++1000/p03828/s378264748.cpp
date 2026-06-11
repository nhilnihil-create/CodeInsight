#include <bits/stdc++.h>
using namespace std;
#define fio                         \
ios_base::sync_with_stdio(false); \
cin.tie(NULL);                    \
cout.tie(NULL);
#define ll long long
#define ull unsigned long long
#define ld long double
#define endl "\n"
#define ff first
#define ss second
#define pi pair<ll, ll>
#define PI 3.141592653589793238462643383279502884L
#define mp make_pair
#define pb push_back
#define sz(x) (ll) x.size()
#define all(x) x.begin(), x.end()
#define time_passed 1.0 * clock() / CLOCKS_PER_SEC
ll MOD = 1e9 + 7;
ll MOD1 = 1e9 + 123;
ll MOD2 = 1e9 + 321;

int main()
{
    fio;
    ll t, a, n, q, k, i, l, m, c, u, f, j, p, r, x, y, s, b, d;
    p= 1001;
    bool ar[p];
    ar[0]=false;
    ar[1]=false;
    for (i = 2; i <= p; i += 1)
        ar[i] = true;
    ar[0] = false;
    ar[1] = false;

    for (i = 2; i * i <= p; i += 1)
    {
        if (ar[i] == true)
            for (j = i * i; j <= p; j += i)
                ar[j] = false;
    }
    map<ll, ll>mp;
    for (i=0;i<p;i++)
        if (ar[i]==true)mp[i]=1;

    cin>>n;

    for (auto h : mp)
    {
        p=h.ff;
        while (p<=n) {
            mp[h.ff]+=n/p;
            p*=h.ff;
        }
    }

    c=1;
    // for (auto h : mp)
    //     cout<<h.ff<<" "<<h.ss<<endl;
    for (auto h : mp)
        c=(c*h.ss)%MOD;
    cout<<c<<endl;


    return 0;
}
