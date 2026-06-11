#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_multiset tree<long long , null_type,less_equal<long long >, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_set tree<long long , null_type,less<long long >, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define ll long long
#define f(i,a,b) for(ll i=a;i<=b;++i)
#define mod 1000000007
const double pi =3.14159265358979323846;
bool isprime(ll n)
{
    if(n<2) return false;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll a,b; char c; cin>>a>>c>>b;
    if(c=='+') cout<<a+b;
    else cout<<a-b;
    return 0;
}
/**
pair<ll,ll>fib(ll n)
{
    if(n==0) return {0,1};
    pair<ll , ll >p=fib(n/2);
    ll c=p.first*(2*p.second - p.first) ;
    ll d=p.second*p.second + p.first*p.first;
    if(n&1) return {d,c+d};
    else return {c,d};
}
**/
/**
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
**/
/**check for perfect square.
ll is_perfect_square(ll n)
{
    ll tp=floor(sqrt(n));
    if(n==(tp*tp)) return tp;
    else return -1;
}
**/
/**
ll biexp(ll a,ll n)
{
    if(n==0) return 1;
    ll res=1;
    while(n>0)
    {
        if(n%2!=0) res*=a;
        a=a*a;
        n=n/2;
    }
    return res;
}
**/
/** sieve implementation**/
/**
    ll N=1299827; // first 100008 primes;
    vector<ll>lp(N+1,0);
    vector<ll>pr;
    for(ll i=2;i<=N;++i)
    {
        if(lp[i]==0)
        {
            lp[i]=i;
            pr.push_back(i);
        }
        for(ll j=0;j<pr.size() and i*pr[j]<=N ;++j)
        {
            lp[i*pr[j]]=pr[j];
        }
    }
**/
/**
bool isprime(ll n)
{
    if(n<2) return false;
    for(ll i=2;i*i<=n;++i)
    {
        if(n%i==0) return false;
    }
    return true;
}
**/
/**factors in sqrt(n);
    ll N=100000;
    vector<vector<ll> >factors(N+1);
    for(ll j=1;j<=N;++j)
    {
        for(ll x=1;x*x<=j;++x)
         {
            if(j%x==0)
            {
                factors[j].push_back(x);
                if(j/x != x) factors[j].push_back(j/x);
            }
         }
    }
**/
/**
vector<pair<ll,ll> >prime_factors(ll n)
{
    vector<pair<ll,ll> >res; ll ct=0;
    if(!(n&1))
    {
        while(!(n&1))
        {
            ct++; n/=2;
        }
        res.push_back({2,ct});
    }
    ct=0;
    for(ll i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            ct++; n/=i;
        }
        if(ct>0) res.push_back({i,ct});
        ct=0;
    }
    if(n!=1) res.push_back({n,1});
    return res;
}
**/
/** calculating n_C_r();
ll ncr(ll n, ll k) {
    ll res = 1;
    for (ll i = 1; i <= k; ++i)
        res = (res*(n-k+i))/i;

    return res;
}
**/
