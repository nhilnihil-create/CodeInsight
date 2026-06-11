#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define int long long int
int i,j;
 main()
{
    int n,x; cin>>n;
    n=2*n;
    int a[n];
 for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int s=0;
    for(i=0;i<n;i=i+2)  s=s+a[i];
    cout<<s<<endl;
}
