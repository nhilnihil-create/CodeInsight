#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  int n,k,x,y,sum=0;
    cin>>n>>k>>x>>y;
    if(k>=n){
        cout<<(n*x)<<endl;
        return 0;
    }
    else{
        sum=(k*x)+((n-k)*y);
    cout<<sum<<endl;
    return 0;
    }
}