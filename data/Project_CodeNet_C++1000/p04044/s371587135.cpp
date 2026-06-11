#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i,n) for( ll i=0 ; i<n ; i++ )
#define f(i, a, b) for( ll i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
ll digits(ll n)
{
    return floor(log10(double(n))) + 1;
}
ll SieveOfEratosthenes(ll n)
{
    vector<bool>prime(n+1);
    int ans = 0;
    for(int i =0;i<=n;i++)
        prime[i] = true;
    prime[1] = false;
    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for(int i = 2;i<=n;i++)
    {
        if(prime[i])
        {
            ans++;
        }
    }
    return ans;
}
void permute(string a, int l, int r)
{
    if (l == r)
    {
        cout<<a<<endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
        }
    }
}
ll modularExponentiation(ll x,ll n,ll M)
{
    ll result = 1;
    ll ans = 1;

    while(n>0)
    {
        if(n % 2 ==1)
        {
            result = (result*x)%MOD;
            ans = (ans + result)%MOD;
        }
        n = n/2;
        if(n>0)
        {

            x = x*x;
        }
    }
    return ans;
}
int d, x, y;
void extendedEuclid(int A, int B) {
    // for computing modular inverse
    // make b as Mod such that gcd of mod and a is 1
    // also the coeff x here will denote the modular inverse of a
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
        // x = y1
        // y = x1 - y1*(a/b);
    }
}
ll fact(ll n)
{
    ll ans = 1;
    for(ll i = 1;i<=n;i++)
        ans = (ans%MOD * i%MOD)%MOD;
    return ans%MOD;
}
ll maxpower(ll n,ll k)
{
    ll count = 0;
    while(n>0)
    {
        n = n/k;
        if(n>0)
            count++;
    }
    return count;
}
bool written(ll n,ll k,string s,ll power)
{
    while(power>=0 && n>0)
    {
            ll x = pow(k,power);
            if(n - x>=0)
            {
                if(s[power] == '1')
                    return false;
                n = n - x;
            }
            power--;
    }
    cout<<n<<endl;
    if(n!=0)
        return false;
    return true;
}
void improvise(string s,ll n,ll k,ll power)
{
    for(int i = power;i>=0;i--)
    {
        ll x = pow(k,i);
        if(n - x>=0)
        {
            s[i] = '1';
            n = n - pow(k,i);
        }
    }
}
int main()
{
    ll n,l;
    cin>>n>>l;
    vector<string>v;
    fi(i,n)
    {
        string s;
        cin>>s;
        v.push_back(s);

    }
    sort(v.begin(),v.end());
    string ans = "";
    fi(i,n)
    {
        string temp = v[i];
        ans += temp;
    }
    cout<<ans;

}

