#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
using ll=long long;
int main()
{
    int n,rafi=0;
    cin>>n;
    int b=n;
    while(n!=0)
    {
        rafi=(rafi*10)+(n%10);
        n=n/10;
    }
   // if(n>0)
        //1 rafi=(rafi*10)+n;
    if(rafi==b)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    return 0;
}
