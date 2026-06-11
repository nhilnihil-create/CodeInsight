#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    int i=1;
    long long  sum=0;
    for(;; i++)
    {
        sum+=i;
        if(sum>=n)
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
