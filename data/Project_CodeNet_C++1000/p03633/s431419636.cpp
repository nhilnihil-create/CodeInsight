#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    int time[n];
    for(int i=0;i<n;i++)
    cin>>time[i];

    int lcm=time[0];
    for(int i=1;i<n;i++)
        lcm=(lcm/__gcd(lcm,time[i]))*time[i];
    cout<<lcm<<endl;
}