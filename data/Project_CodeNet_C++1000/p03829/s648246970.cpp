#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

#define endl '\n'
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int MAXN = 1e5 + 5;
ll fastPow(ll x, ll b)
{
    if (b == 0)
        return 1;
    else if (!(b & 1))
    {
        return fastPow(x * x, b / 2);
    }
    else
        return x * fastPow(x * x, (b - 1) / 2);
}
//__builtin_popcount ();
int main()
{
    FAST 
ll n,a,b;
cin>>n>>a>>b;
ll arr[n];
for (int i = 0;i<n;i++)
    cin >> arr[i];
ll sum = 0;
for (int i = 1; i < n;i++)
{
    sum += min((arr[i] - arr[i - 1]) * a, b);
}
cout << sum << endl;
return 0;
}