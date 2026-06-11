#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;
int m=2*n;
int a[m],i;
for(i=0;i<m;i++)
cin>>a[i];
sort(a,a+m);
int s=0;
for(i=0;i<m;i+=2)
s+=a[i];
cout<<s;
     return 0;
}