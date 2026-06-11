#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, x;

ll solve(ll a, ll b)
{
    if(a<b) return solve(b, a);
    if(a%b==0) return b*(a/b)*2-b;
    return solve(a%b, b)+a/b*b*2;
}

int main()
{
    int i, j;
    scanf("%lld%lld", &n, &x);
    printf("%lld", solve(x, n-x)+n);
}
