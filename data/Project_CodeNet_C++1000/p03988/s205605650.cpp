#include "bits/stdc++.h"
using namespace std;
#define int long long
#define double long double
// #define endl '\n'
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
    int fact[500010], factinv[500010] , coefficientflag = 0;
    void Util_nCr()
    {
        fact[0] = 1 , factinv[0] = 1;
        repp(i,1,500010)
        {
            fact[i] = (fact[i-1] * i)%mod;
            factinv[i] = (factinv[i-1] * inverse(i))%mod;
        }
    }
    int nCr(int n , int r)
    {
        if(!coefficientflag) coefficientflag = 1 , Util_nCr();             
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

int sumSubarrayMins(int A[], int n) 
{ 
    int left[n], right[n]; 
    stack<pair<int, int> > s1, s2; 
    for (int i = 0; i < n; ++i) { 
        int cnt = 1; 
        while (!s1.empty() && (s1.top().first) > A[i]) { 
            cnt += s1.top().second; 
            s1.pop(); 
        } 
  
        s1.push({ A[i], cnt }); 
        left[i] = cnt; 
    } 
    for (int i = n - 1; i >= 0; --i) { 
        int cnt = 1; 
        while (!s2.empty() && (s2.top().first) >= A[i]) { 
            cnt += s2.top().second; 
            s2.pop(); 
        } 
  
        s2.push({ A[i], cnt }); 
        right[i] = cnt; 
    } 
    int result = 0; 
    for (int i = 0; i < n; ++i) 
        result = (result + A[i] * left[i] * right[i]); 
    return result; 
} 

void solve() 
{
    int n , x;
    cin >> n;
    int mx = 0;
    map<int,int> m;
    int temp;
    rep(i,n)
    {
        cin >> temp;
        m[temp]++;
        mx = max(mx,temp);
    }
    int mn = (mx+2)/2;
    reppr(i,mx+1,mn)
    {
        if(m[i]<2)
        {
            cout << "Impossible\n";
            return;
        }
        m[i]-=2;
    }
    if(mx%2==0)
        m[mx/2]-- , mn--;
    mn++;
    for(auto i : m)
    {
        if(i.ss>0 && i.ff<mn)
        {
            cout << "Impossible\n";
            return;
        }
    }
    cout << "Possible\n";
}  