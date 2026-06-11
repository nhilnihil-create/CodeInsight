#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=205;
int n;
int a[MAXN];
int ans;
int main()
{
    cin>>n;
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    sort(a+1,a+2*n+1);
    for(int i=1;i<=2*n;i+=2) ans+=a[i];
    cout<<ans<<endl;
    return 0;
}