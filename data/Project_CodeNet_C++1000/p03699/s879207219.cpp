#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

int main(){
int n;
cin>>n;
int s[n];
int ans=0;
vector<int>a;
bool flag=false;
rep(i,n){
  cin>>s[i];
  ans+=s[i];
  if(s[i]%10!=0){
    flag=true;
a.push_back(s[i]);
  }
}if(flag){
sort(a.begin(),a.end());
}
if(ans%10==0&&flag){
  cout<<ans-a[0]<<endl;
}else if(ans%10==0){
  cout<<0<<endl;
}else
{
  cout<<ans<<endl;
}


  return 0;
}
