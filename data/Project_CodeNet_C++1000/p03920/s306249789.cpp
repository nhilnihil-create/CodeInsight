#include <bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(ll (i) = 0; (i) < (n); ++(i))
#define rrep0(i,n) for(ll (i) = (n) - 1; (i) >= 0; --(i))
#define rep1(i,n) for(ll (i) = 1; (i) <= (n); ++(i))
#define rrep1(i,n) for(ll (i) = (n); (i) >= 1; --(i))
#define nfor(i,a,b) for(ll (i) = (a); (i) < (b); ++(i))
#define ll long long
#define mod (1000000007)
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define yes cout << "yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define no cout << "no" << endl;
#define all(x) (x).begin(),(x).end()

ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    return a / g * b;
}

ll fac(ll n){
    ll t = 1;
    rep1(i, n + 1)t *= i;
    return t;
}

int main()
{
    ll n,a = 0,cnt = 1,ans = 1;
    cin >> n;
    rep1(i, n){
        a += i;
        ans = i;
        if (a == n) {
            cnt = 0;
            break;
        }else if (a > n){
            cnt = a - n;
            break;
        }
    }
    rep1(i, ans){
        if (i != cnt) {
            cout << i << endl;
        }
    }
    return 0;
}
