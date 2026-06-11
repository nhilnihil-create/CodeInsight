#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
ll f(ll a, ll b)
{
    string s;
    int n, num;
    num = max(a, b);
    s = to_string(num);
    n = s.size();
    return n;
}
int main()
{
    ll n;
    cin>>n;
    ll a, b, ans = 1 , d = INT_MAX, root;
    root = sqrt(n);
    for(ll i = root; i>=1; i--)
    {
        if(n%i == 0)
        {
            a = i;
            b = n/i;
            ans = f(a, b);
            d = min(d, ans);
        }
    }
    cout<<d;
    return 0;
}

