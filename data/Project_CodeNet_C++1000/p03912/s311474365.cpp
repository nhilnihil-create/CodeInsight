#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,x[100000];
  int s[100001]={},c[100001]={},ans=0;
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>x[i],s[x[i]%m]++,c[x[i]]++;
  for(int i=0;i<=m/2;i++){
    if(i==0)ans+=s[i]/2,s[i]%=2;
    else if(m%2==0&&i==m/2)ans+=s[i]/2,s[i]%=2;
    else{
      int M=min(s[i],s[m-i]);
      ans+=M;
      s[i]-=M,s[m-i]-=M;
    }
  }
  for(int i=0;i<=1e5;i++){
    if(s[i%m]>=2&&c[i]>=2){
      int M=min(c[i],s[i%m]);
      s[i%m]-=M/2*2;
      ans+=M/2;
    }
  }
  cout<<ans<<endl;
  return 0;
}
