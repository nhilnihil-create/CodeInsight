#include<bits/stdc++.h>
using namespace std;

int main()
{
string S;
cin>>S;
int n=S.size()-1;long long ans=0;
for(int bit=0;bit<(1<<n);bit++)
{
  long long sum=S[n]-'0',reset=1;
  for(int i=n-1;i>-1;i--)
  {
    if(bit&(1<<i))reset=1;
    else reset*=10;
    sum+=(S[i]-'0')*reset;   
  }
  ans+=sum;
}
printf("%lld\n",ans);
}