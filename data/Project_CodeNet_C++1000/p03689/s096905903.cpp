#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vpipii vector<pipii>
#define vpiipi vector<piipi>
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define pipii pair<int,pii>
#define piipi pair<pii,int>
#define pld pair<long double,long double>
#define mod 1000000007
// #define mod 1000000009
// #define mod 163577857 
// #define mod 998244353
#define rep(i,n) for (int i = 0; i < n; i++)
#define repp(i,a,b) for(int i = a ; i<b ; i++)
#define reppr(i,a,b) for(int i = a-1 ; i>=b ; i--)
#define repr(i,n) for (int i = n - 1; i >= 0; i--)
#define ff first
#define ss second
#define pc putchar_unlocked
#define gc getchar_unlocked
#define inf 9223372036854775807
#define infn -9223372036854775807
#define pi 3.14159265358979323846
#define eps 0.0000000001
#define sp << " " <<
#define setprec(x) cout << fixed << setprecision(x);
#define REVERSE(a) reverse(all(a));
#define SORT(a) sort(all(a));
#define all(n) n.begin(),n.end()

//GCD and LCM
    int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }
    int lcm (int a, int b) { return a / gcd(a, b) * b; }
 
//Modular Exponentiation
    int powmod(int x,int y) 
    { 
        if (y == 0) return 1; 
        int p = powmod(x, y/2) % mod; 
        p = (p * p) % mod;   
        return (y%2 == 0)? p : (x * p) % mod; 
    }
 
//Modular Inverse
    int inverse(int a) 
    { 
       return powmod(a,mod-2); 
    }

//Binomial Coefficients
    const int limbin = 500001;
    int fact[limbin], factinv[limbin] , coefficientflag = 0;
    void Util_nCr()
    {
        fact[0] = 1 , factinv[0] = 1;
        repp(i,1,limbin)
        {
            fact[i] = (fact[i-1] * i)%mod;
            factinv[i] = (factinv[i-1] * inverse(i))%mod;
        }
    }
    int nCr(int n , int r)
    {
        if(!coefficientflag) coefficientflag = 1 , Util_nCr();
        if(n<r) return 0;             
        return ((fact[n] * inverse(fact[n-r]) % mod * inverse(fact[r]))%mod) ;
    }

void solve();
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t; 
    rep(i,t)
    {
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
}

int test[502][502];
void solve()
{ 
    int n, m, a, b, ans = 0; cin >> n >> m >> a >> b;
    int ka = a * b - 2;
    for (int h = 1; h <= n; h++) {
        for (int i = 1; i <= m; i++) {
            if (h % a == 0 && i % b == 0) { 
                test[h][i] = 0 - (mod - 7); ans -= mod - 7;
            }
            else if ((h - 1) % a == 0 && (i - 1) % b == 0) {
                test[h][i] = mod - 8 - ka; ans += mod - 8 - ka;
            }
            else { test[h][i] = 1; ans += 1; }
        }
    }
    if (ans > 0) {
        cout << "Yes\n";
        for (int h = 1; h <= n; h++) {
            cout << test[h][1];
            for (int i = 2; i <= m; i++) {
                cout << ' ' << test[h][i];
            }
            cout << endl;
        }
    }
    else
        cout << "No\n";
}