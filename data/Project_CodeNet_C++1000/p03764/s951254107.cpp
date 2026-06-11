#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 1e6+5;
string s;
ll n , m , cnt[N] , x[N] , y[N] , mod=1e9+7;

int mul(int a, int b)
{
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (1ll * a * b) % mod;
}

int add(int a, int b)
{
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> x[i];
    for(int i=1; i<=m; i++)
        cin >> y[i];

    sort(x+1 , x+n+1);
    sort(y+1 , y+m+1);

    vector<ll> v,v2;
    for(int i=1; i<n; i++)
        v.push_back(add(x[i+1],-x[i]));
    for(int i=1; i<m; i++)
        v2.push_back(add(y[i+1],-y[i]));

    ll sum=0 , sum2=0 , p=(int)v.size() , st=(int)v.size();

    for(int i=0; i<v.size(); i++)
    {
        sum = add(sum , mul(v[i] , st));
        p = add(p , -2);
        st = add(st , p);
    }

    p=(int)v2.size() , st=(int)v2.size();
    for(int i=0; i<v2.size(); i++)
    {
        sum2 = add(sum2 , mul(v2[i] , st));
        p = add(p , -2);
        st = add(st , p);
    }

    cout << mul(sum,sum2) << '\n';
//
    return 0;
}