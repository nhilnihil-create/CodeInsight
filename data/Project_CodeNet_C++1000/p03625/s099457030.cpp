#include <bits/stdc++.h>
using namespace std;
int main()
{    long long int n,a,p;
    cin>>n;
    map<int,int>mp;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        mp[a]++;
        if(mp[a]==2){v.push_back(a);mp[a]=0;}
    }
    sort(v.begin(),v.end());
    p=(int)v.size();
    if(p<2) cout<<"0"<<endl;
    else cout <<((long long int)v[p-1]*v[p-2])<<endl;
    return 0;
}
