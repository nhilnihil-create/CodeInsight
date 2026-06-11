#include<bits/stdc++.h>
using namespace std;
#define INF 123456789012345678

int main()
{
  int n,m;cin>>n>>m;
  vector<long long> a(m);
  vector<long long> b(m);
  vector<long long> c(m);
  int i;
  for(i=0;i<m;i++)cin>>a.at(i)>>b.at(i)>>c.at(i);
  vector<vector<long long>> edge(n,vector<long long>(n,INF));
  for(i=0;i<m;i++)
  {
    a.at(i)--;
    b.at(i)--;
    c.at(i)*=(-1);
    edge.at(a.at(i)).at(b.at(i))=c.at(i);
  }
  for(i=0;i<n;i++)edge.at(i).at(i)=0;
  vector<long long> d(n,INF);
  d.at(0)=0;
  int count=0;
  while(true)
  {
    for(i=0;i<m;i++)
    {
      if(d.at(a.at(i))!=INF&&d.at(b.at(i))>d.at(a.at(i))+edge.at(a.at(i)).at(b.at(i)))
      {
        d.at(b.at(i))=d.at(a.at(i))+edge.at(a.at(i)).at(b.at(i));
      }
    }
    count++;
    if(count==n-1)break;
  }
  vector<bool> negative(n,false);
  while(true)
  {
    for(i=0;i<m;i++)
    {
      if(d.at(a.at(i))!=INF&&d.at(b.at(i))>d.at(a.at(i))+edge.at(a.at(i)).at(b.at(i)))
      {
        d.at(b.at(i))=d.at(a.at(i))+edge.at(a.at(i)).at(b.at(i));
        negative.at(a.at(i))=true;
        negative.at(b.at(i))=true;
      }
    }
    count++;
    if(count==n)break;
  }
  if(negative.at(n-1))cout<<"inf"<<endl;
  else cout<<-d.at(n-1)<<endl;
}
