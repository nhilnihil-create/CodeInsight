#include<bits/stdc++.h>
#define int long long
#define wyhsb signed
using namespace std;
int n,a[101101],ans;
wyhsb main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) if(a[i]==a[i-1])ans++;
    if(ans&1)ans++;
    cout<<n-ans<<"\n";
    exit(0);
}