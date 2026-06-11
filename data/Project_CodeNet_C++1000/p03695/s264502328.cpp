#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n ;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if( n==1 )
    {
        cout<<1<<" "<<1;
        return 0;
    }
    int * b = new int[9]();
    for(int i=0;i<n;i++)
    {
        if( a[i] >=1 && a[i ]<= 399)
            b[0]++;
        if( a[i] >=400 && a[i ]<= 799)
            b[1]++;
        if( a[i] >=800 && a[i ]<= 1199)
            b[2]++;
        if( a[i] >=1200 && a[i ]<= 1599)
            b[3]++;
        if( a[i] >=1600 && a[i ]<= 1999)
            b[4]++;
        if( a[i] >=2000 && a[i ]<= 2399)
            b[5]++;
        if( a[i] >=2400 && a[i ]<= 2799)
            b[6]++;
        if( a[i] >=2800 && a[i ]<= 3199)
            b[7]++;
        if( a[i] >=3200 )
            b[8]++;
    }
    int min =0, max =0;
    for(int i=0;i<8;i++)
    {
        if( b[i] >0)
            min++;
    }
    max = min + b[8];
    if( min ==0)
    {
        cout<<1<<" "<<max;
    }
    else cout<<min<<" "<<max;

}