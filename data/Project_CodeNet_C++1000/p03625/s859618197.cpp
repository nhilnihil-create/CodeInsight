#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<long long int,long long int>m;
    long long int n,x,c=0;
    cin>>n;
    while(n--)
    {
        cin>>x;
        m[x]++;
    }
    vector<long long int>v,u;
    v.push_back(0);
    v.push_back(0);
    u.push_back(0);
    u.push_back(0);
    for( map<long long int,long long int>::iterator it=m.begin();it!=m.end();it++)
    {
        if(it->second>=2)
        {
            v.push_back(it->first);
        }
        if(it->second>=4)
        {
            u.push_back(it->first);
        }
    }
    sort(v.begin(),v.end());
    sort(u.begin(),u.end());
    long long int area1,area2;
    area2=u[u.size()-1]*u[u.size()-1];
    if(v.size()==2 || v.size()==3 ) area1=0;
    else area1=v[v.size()-1]*v[v.size()-2];
    area1=max(area1,area2);
    cout<<area1<<endl;
    return 0;
}
