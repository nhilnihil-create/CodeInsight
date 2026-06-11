#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

long long int a[100000],x,y,n;

int fax(int z)
{
    int g=x-y,min=y*z;
    long long int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<=min) break;
        sum+=(a[i]-min)/g;
        if((a[i]-min)%g)
            sum++;
    }
    if(sum<=z)
        return 1;
    else return 0;
}

int main()
{
    cin>>n>>x>>y;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int mind,left,right;
    left=0;
    right=a[n-1]/y+1;
    while(left<right)
    {
        mind=left+(right-left)/2;
        if(fax(mind))
            right=mind;
        else
            left=mind+1;
    }
    cout<<left<<endl;
    return 0;
}
