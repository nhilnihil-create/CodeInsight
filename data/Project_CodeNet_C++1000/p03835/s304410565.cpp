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
#define fall(i, a, b) for (int i = a; i < b; i++)
#define sz(x) (ll) x.size()
#define all(x) x.begin(), x.end()
#define ed cout << "ed";
#define time_passed 1.0 * clock() / CLOCKS_PER_SEC
ll MOD = 1e9 + 7;
ll MOD1 = 1e9 + 123;
ll MOD2 = 1e9 + 321;

int main()
{
    fio;
    ll t, a, n, q, k, i, l, m, c, u, f, j, p, r, x, y, s, b, d;
    cin>>k>>s;c=0;
    for(i=0;i<=k;i++)
    for(j=0;j<=k;j++)
    if(s-i-j>=0 && s-i-j<=k)c++;
    cout<<c<<endl;
    
    return 0;
}
