#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    ll ans=0,sum=0;
    for (int i=n-1;0<=i;--i)
    {
        ll cnt;
        if((a[i]+sum) % b[i] == 0) 
            cnt = 0;
        else 
            cnt = b[i] - ((a[i]+sum) % b[i]);
        ans += cnt;
        sum += cnt;
    }
    cout<<ans<<endl;
    return 0;
}
