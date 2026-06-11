#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >a(200005,vector<int>());

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,j,k;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>j>>k;
        a[j].push_back(k);
        a[k].push_back(j);
    }
     for(i=2;i<=n-1;i++)
     {
         k=0;
         for(j=0;j<a[i].size();j++)
         {
             if(a[i][j]==1 || a[i][j]==n)
             {
                 k++;
             }
         }
         if(k==2)
         {
             cout<<"POSSIBLE"<<endl;
             return 0;
         }
     }
     cout<<"IMPOSSIBLE"<<endl;


}
