#include<iostream>
using namespace std;
int main(){
  long n,m,sum1=0,sum2=0,b4a,a,ans,mod=1000000007,i;
  cin>>n>>m;
  cin>>b4a;
  for(i=1;i<n;i++){
    cin>>a;
    sum1=(sum1+(a-b4a)*i%mod*(n-i)%mod)%mod;
    b4a=a;
  }
  cin>>b4a;
  for(i=1;i<m;i++){
    cin>>a;
    sum2=(sum2+(a-b4a)*i%mod*(m-i)%mod)%mod;
    b4a=a;
  }
  ans=sum1*sum2%mod;
  cout<<ans<<endl;
}
