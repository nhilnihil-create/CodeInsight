#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[201],s=0;
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
    for(int i=1;i<2*n;i+=2) s+=a[i];
    cout<<s<<endl;
}