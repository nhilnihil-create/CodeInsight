#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,l[1000],ans=0,m;
    cin>>n;
    m = 2*n;
    vector<int>v;
    for(int i=0;i<m;i++)
    {
        cin>>l[i];
    }
    sort(l,l+m);
    for(int i=0;i<m;i=i+2)
    {
        v.push_back(l[i]);
    }

    for(int i=0;i<v.size();i++)
    {
        ans = ans + v[i];
    }
    cout<<ans<<endl;
}
