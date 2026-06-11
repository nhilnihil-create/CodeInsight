#include<bits/stdc++.h>
using namespace std;
vector< vector <long long > >C;
void comb()
{
  C.resize(51);
  C[0].push_back(1);
  for(int i=1;i<=50;i++)
  {
    C[i].resize(i+1);
    C[i][0]=1;
    C[i][i]=1;
  }
  for(int i=2;i<51;i++)
  {
    for(int j=1;j<i;j++)C[i][j]=C[i-1][j]+C[i-1][j-1];
  }
}
int main()
{
  comb();
  int n,p;
  cin>>n>>p;
  vector<int>a(n);
  int even=0,odd=0;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)
  {
    if(a[i]%2==0)even++;
    else odd++;
  }
  long long eans=pow(2,even);
  long long oans=0;
  if(p==0)
  {
    
    for(int i=0;i<=odd;i+=2)
    {
      oans+=C[odd][i];
    }
  }
  else 
  {
    for(int i=1;i<=odd;i+=2)
    {
      oans+=C[odd][i];
    }
  }
  long long ans=eans*oans;
  cout<<ans<<endl;
  //cout<< even <<' '<<odd<<endl;
  return 0;
}
    