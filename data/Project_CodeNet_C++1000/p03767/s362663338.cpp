#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

long long int n,n1,n2,n3,a,sm,c,ar[300005];
int main()
{
    cin>>n;
    n1=3*n;
    for(a=0; a<n1; a++)
    {
        cin>>ar[a];
    }
    sort(ar+0,ar+0+n1);
    n2=2*n;
    n3=n/2;
    sm=0;

    for(a=n; a<n1; a=a+2)
    {
        sm=sm+ar[a];


    }


    cout<<sm<<endl;
    return 0;
}
