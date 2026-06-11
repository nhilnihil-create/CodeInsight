#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[200000],i,j,b[3]={0},k=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(j=n-1;j>=0;j--)
    {       
        if(a[j]==a[j-1]) 
        {
            b[k]=a[j--];
            k++;
            if(k==2)
            {
                break;
            }
        }         
    }
    cout<<(b[0]*b[1])<<endl;
    return 0;
}