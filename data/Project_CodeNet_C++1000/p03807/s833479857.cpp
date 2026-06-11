#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define PI			2*acos(0.0)
int main()
{
    int n;
    cin >>n;
    int a[n],i,even=0,odd=0;
    for(i=0;i<n;i++)
    {
        cin >>a[i];
        if(a[i]%2)
            odd++;
        else
            even++;
    }
    if(odd%2)
        cout <<"NO";
    else
        cout <<"YES";
    return 0;
}