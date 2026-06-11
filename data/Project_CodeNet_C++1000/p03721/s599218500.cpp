// by The_One_Solver
#include<bits/stdc++.h>
using namespace std;
long long int n,v,k,c,a,b;
map<long long ,long long >mp;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        mp[a]+=b;
    }
    for(int i=0;i<100001;i++)
    {
        k=k-mp[i];
        if(k<=0){cout<<i;break;}
    }


    return 0;
}
