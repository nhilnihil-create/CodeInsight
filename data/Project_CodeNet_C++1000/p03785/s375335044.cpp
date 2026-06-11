#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c,k;
  cin >> n >> c >> k;
  int i,t[100010];
  for(i=0;i<n;i++){
    cin >> t[i];
  }
  sort(t,t+n);
  int sum=1,time=t[0],ans=0;
  for(i=1;i<n;i++){
    if(sum==c){
      ans++,sum=1,time=t[i];
    }
    else if(t[i]-time>k){
      if(sum%c==0){
        ans+=sum/c;
      }
      else{
        ans+=sum/c+1;
      }
      sum=1,time=t[i];
    }
    else{
      sum++;
    }
  }
  if(sum%c==0){
    ans+=sum/c;
  }
  else{
    ans+=sum/c+1;
  }
  cout << ans << endl;
}