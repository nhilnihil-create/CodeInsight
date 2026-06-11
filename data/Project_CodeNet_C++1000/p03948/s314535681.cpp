#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    int ar[n+1];
    int dif,ct=0;
    int max_dif=-1;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    int mn;
    mn=ar[0];
    for(int i=1; i<n; i++)
    {
        if(ar[i]<mn)
        {
            mn=ar[i];
        }
        dif=ar[i]-mn;
        if(dif>max_dif)
        {
            max_dif=dif;
            ct=1;
        }
        else if(dif==max_dif)
        {
            ct++;
        }
    }
    cout<<ct<<endl;
    return 0;
}
