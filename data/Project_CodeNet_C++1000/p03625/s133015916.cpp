#include<bits/stdc++.h>
using namespace std;
int a[27];
int main()
{
    long long int i,j,k,z,t,x,y,n;
    map<long long int,long long int>m;
    vector<long long int>v;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        m[x]++;
        if(m[x]>1)
        {
            v.push_back(x);
            m[x]=0;
        }

    }
    sort(v.begin(),v.end(),greater<int>());
    if(v.size()<2)
        cout<<0<<endl;
    else
    {
        x=v[0]*v[1];
        cout<<x<<endl;
    }
}