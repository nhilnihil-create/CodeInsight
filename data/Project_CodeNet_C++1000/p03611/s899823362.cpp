#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;cin>>N;
  int a[N];
  for(int i=0;i<N;i++)cin>>a[i];
  int num[100001];fill(num,num+100001,0);
  int aminus=0;
  for(int i=0;i<N;i++)
  {
    num[a[i]+1]++;num[a[i]]++;num[a[i]-1]++;
    if(a[i]-1==-1)aminus++;
  }
  int ans=aminus;
  for(int i=0;i<100001;i++)ans=max(ans,num[i]);
  cout<<ans<<endl;
}