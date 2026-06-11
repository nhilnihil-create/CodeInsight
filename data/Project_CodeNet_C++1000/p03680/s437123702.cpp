#include <bits/stdc++.h>
using namespace std;
   int main()
{
    int n,t=0,f=0;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        t++;
        if(a[f]==2)
            break;
        else
            f=a[f]-1;
    }
    if(t<n)cout<<t;
    else cout<<-1;
    return 0;
   }