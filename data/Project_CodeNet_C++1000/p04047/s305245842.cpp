#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,s=0;
    cin>>n;
    n*=2;
    int a[n];
    
    for(i=0;i<n;i++)
    cin>>a[i];
    
    sort(a,a+n);
    for(i=0;i<n;i+=2)
    s+=a[i];
    
    cout<<s;
    return 0;
}