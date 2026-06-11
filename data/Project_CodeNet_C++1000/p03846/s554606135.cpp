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
    cin>>n;
    vector<int>v(n, 0);map<int, int>mp;
    for (i=0;i<n;i++)
        cin>>v[i], mp[v[i]]++;
    if (n%2==0)f=1;
    else f=0;
    c=0;if(mp[0]>1)c=1;
    for (i=0;i<n;i++)
        if (v[i]%2!=f && mp[v[i]]>2 )
        {
            c=1;break;        
         }
    if (c==1)cout<<0<<endl;
    else {
        n/=2;
        f=1;
        while (n--) {
            f=(f*2)%MOD;
   
        }
        cout<<f<<endl;
    }
    return 0;
}
