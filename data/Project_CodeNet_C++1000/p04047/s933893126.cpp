#include<bits/stdc++.h>
using namespace std;
const int maxn=10001;
int a[maxn],b[maxn],n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;i++)cin>>a[i];
    sort(a+1,a+1+2*n);
    for(int i=1;i<=n*2;i+=2)ans+=a[i];
    cout<<ans;

}