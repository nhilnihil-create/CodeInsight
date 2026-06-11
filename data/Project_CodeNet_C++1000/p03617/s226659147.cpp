#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define PI 3.141592653L
#define F first;
#define S second;
#define MP make_pair;
const ll INF = (ll)1e18;
const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;

int parent[N];

int gcd(int a, int b) { 
    if (a == 0) 
        return b;  
    return gcd(b%a, a);  
} 
   
int lcm(int a, int b) {  
    return (a*b)/gcd(a,b);  
} 

ll pow(ll x, ll y, ll p) {
    if(y == 0) return 1;
    ll res = 1;
    x %= p;
    if(x == 0) return 0LL;
    while(y > 0) {
        if(y & 1) res = (res*x) % p;
        y >>= 1;
        x = (x*x) % p;
    }
    return res;
}

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    h = min(2*q,h);
    s = min(2*h,s);
    ll res = 0;
    if(2*s<d) {
        res = n*s;
    }
    else {
        res = n/2*d + n%2*s;
    }
    cout << res << endl;
    return 0;
}
