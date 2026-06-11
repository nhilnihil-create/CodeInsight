#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int ans;
  int a=-1;
  for(int i=1; i<=n; i++){
    int count=0;int s=i;
    while(s%2==0&&s>0){
      s=s/2;
      count++;
    }
    if(count>a){
      a=count;
      ans=i;
    }
  }
  cout<<ans<<endl;
}
