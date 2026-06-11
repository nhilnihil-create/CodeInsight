#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n , w , t;
    cin >> n >> w >> t;
    ll ara[n+10] ;
    for(int i=1; i<=n; i++)
    {
        cin >> ara[i] ;
    }
    ll sum = 0;
    for(int i=2; i<=n; i++)
    {
        ll dis = ara[i] - ara[i-1] ;
        sum += min(dis*w,t);
    }
    cout << sum << endl;
}
