#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> count(100005);
  for(int i=0;i<n;i++){
  int a;
  cin>>a;
  count[a]++;
  if(a-1==-1){
    count[100001]++;
  }
  else{
    count[a-1]++;
  }
  count[a+1]++;
  }
  int ans=0;
  for(int i=0;i<count.size();i++){
    ans=max(ans,count[i]);
  }
  cout<<ans<<endl;
}