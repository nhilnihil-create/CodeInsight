#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define        optimize           ios::sync_with_stdio(0); cin.tie(0);
#define PI    acos(-1.0)
#define pb push_back
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define RESET(a, b) memset(a, b, sizeof(a))
#define pii pair <int, int>
#define pll pair <ll, ll>
#define setbiti(x) __builtin_popcount(x)
#define setbitll(x) __builtin_popcountll(x)
#define gcd(a, b) __gcd(a, b)

#define        MX        200005

int main()
{
    optimize
    ll n, k, x, y;
    cin>>n>>k>>x>>y;

    if(k >= n){
        cout<<n*x<<endl;
        return 0;
    }

    ll prothom = k, baki = n-k;

    cout<<prothom*x+baki*y<<endl;
}
