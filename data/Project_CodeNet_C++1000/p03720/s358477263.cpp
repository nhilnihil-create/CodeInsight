#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m,a,b;
   cin>>n>>m;
   vector<int>v[300];
   for(int i=1;i<=m;i++)
   {
       cin>>a>>b;
       v[a].push_back(b);
       v[b].push_back(a);
   }
   for(int i=1;i<=n;i++)
   {
       cout<<v[i].size()<<endl;
   }
}
