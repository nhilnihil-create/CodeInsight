#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,i,sum=0,temp=0;
    cin>>n;
    long long a[3*n];
    for(i=0;i<3*n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3*n);
    for(i=3*n-2; ;i=i-2)
    {
        if(temp==n)
        {
            break;
        }
        sum=sum+a[i];
        temp++;
    }
    cout<<sum;
    return 0;
}