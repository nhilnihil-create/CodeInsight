#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  cin>>n;
int p=10;
  int ans=0;
  int temp=n;
  while(temp>0)
  {
    ans=ans*p+(temp%10);
    temp=temp/10;
    
  }
  //cout<<ans<<" "<<n<<endl;
  if(ans==n)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}