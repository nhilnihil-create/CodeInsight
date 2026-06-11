#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,M;cin>>N>>M;
  pair<int,int> ab[N];pair<int,int> cd[M];
  int num[M];fill(num,num+M,0);
  for(int i=0;i<N;i++)cin>>ab[i].first>>ab[i].second;
  for(int i=0;i<M;i++)cin>>cd[i].first>>cd[i].second;
  for(int i=0;i<N;i++)
  {
    pair<int,int> p={1000000000,-1};
    for(int j=0;j<M;j++)
  	{
    	int dist=abs(ab[i].first-cd[j].first)+abs(ab[i].second-cd[j].second);
    	if(p.first>dist)p.first=dist,p.second=j;
  	}
    cout<<p.second+1<<endl;
  }
}