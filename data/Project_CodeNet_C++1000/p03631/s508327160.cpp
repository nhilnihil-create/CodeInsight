 #include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,temp,sum=0,r;
  cin>>n;
  temp = n;
  while(temp!=0)
  {
    r = temp%10;
    sum = sum*10 + r;
    temp=temp/10;
  }
  
  if(sum==n)
  cout<<"Yes"<<endl;
  else
  cout<<"No"<<endl;
}