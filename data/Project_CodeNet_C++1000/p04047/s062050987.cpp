#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=2*n;i++)cin>>a[i];
    sort(a+1,a+2*n+1);
    for(int i=1;i<=2*n;i+=2)cnt+=a[i];
    cout<<cnt<<'\n';
    return 0;
}