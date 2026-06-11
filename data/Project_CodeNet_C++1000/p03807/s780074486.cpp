#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,i,cnt=0;
    cin>>n;
    long long a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%2==1)
        {
            cnt++;
        }
    }
    if(cnt%2==0)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
}