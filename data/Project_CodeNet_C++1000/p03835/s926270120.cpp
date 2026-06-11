#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int i,j,k,m;
main()
{
    int c=0;
    int k,s;cin>>k>>s;
    for(i=0;i<=k;i++)
    {
        for(j=0;j<=k;j++)
        {
            int f=i+j;
            if((s-f)>=0&&(s-f)<=k) c++;
        }
    }
    cout<<c<<endl;
}
