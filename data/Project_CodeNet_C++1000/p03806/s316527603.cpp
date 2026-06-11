#include<bits/stdc++.h>
using namespace std;
#define INF 100000

int main()
{
  int n,ma,mb;cin>>n>>ma>>mb;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  int i,j,k;
  for(i=0;i<n;i++)cin>>a.at(i)>>b.at(i)>>c.at(i);
  vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n*10+1,vector<int>(n*10+1,INF)));
  for(i=0;i<=n;i++)dp.at(i).at(0).at(0)=0;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n*10;j++)
    {
      for(k=1;k<=n*10;k++)
      {
        if(j-a.at(i-1)>=0&&k-b.at(i-1)>=0)
        {
          dp.at(i).at(j).at(k)=min(dp.at(i-1).at(j).at(k),dp.at(i-1).at(j-a.at(i-1)).at(k-b.at(i-1))+c.at(i-1));
        }
        else dp.at(i).at(j).at(k)=dp.at(i-1).at(j).at(k);
      }
    }
  }
  int ans=INF;
  for(i=1;max(ma,mb)*i<=10*n;i++)
  {
    if(dp.at(n).at(i*ma).at(i*mb)<ans)ans=dp.at(n).at(i*ma).at(i*mb);
  }
  if(ans==INF)cout<<-1<<endl;
  else cout<<ans<<endl;
}
