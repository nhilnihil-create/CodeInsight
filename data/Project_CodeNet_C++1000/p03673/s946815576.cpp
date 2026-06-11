#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int a[200010];
int b[200010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];

    int pos=0;
    for(int i=n-1;i>=0;i-=2,pos++)b[pos]=a[i];
    for(int i=n%2;i<n;i+=2,pos++)b[pos]=a[i];

    for(int i=0;i<n;i++)cout<<b[i]<<" ";

    return 0;
}
