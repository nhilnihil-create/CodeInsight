#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define in insert
#define PI 3.1415926535897932384626433832795
#define F first
#define S second
#define aLL(str) (str).begin(), (str).end()
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define ll long long
#define ld long double
#define lcm(a, b) (a * b) / __gcd(a, b)
#define flu(i, a, b) for (ll i = a; i < b; i++)
#define blu(i, a, b) for (ll i = a; i >= b; i--)
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define Unique(X) (X).erase(unique(all(X)), (X).end())
#define all(v) v.begin(), v.end()
typedef vector<ll> vl;
typedef map<ll, ll> ml;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
char e = '\n';

const ll MOD = 1e9 + 7;

ll i, j, le;

int sv(int x)
{
    int n = 200000;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    if (prime[x])
        return 1;
    else
        return 0;
}

int main()
{
    IOS;
    int t;
    //cin >> t;
    t=1;
    while (t--)
    {
        ll n;
    cin >> n;
    vl num(1e3+100,1);
    flu(i,1,n+1){
        ll tem=i;
        flu(j,2,n+1){
            while(tem%j==0){
                num[j]++;
                tem/=j;
            }
        }
    }
    ll ans=1;
    flu(i,2,n+1){
        ans*=num[i];
        ans%=MOD;
    }
    cout << ans << e;
    }
    return 0;
}