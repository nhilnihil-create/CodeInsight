#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int nmax=100005;
int a[nmax];
int n,i,x,d1,d2;
bool decomp(int a,int b)
{
    return a>b;
}
bool marg()
{
    return (i>=a[i+1]);
}
int main()
{
   // freopen("data.in","r",stdin);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,decomp);
    a[0]=a[1];
    for(i=0;!marg();i++);
    x=i-1;
    d1=1-(a[x+1]-x)%2;
    for(i=x;i<=n&&a[i+1]>x;i++);
    i--;
    d2=(i-x)%2;
    if(d1||d2) cout<<"First";
    else cout<<"Second";
    return 0;
}
