#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  int a=0,ans=0;
  vector<int> vec;
  for(int i=1;i<=n;++i){
    vec.push_back(pow(2,i));
  }
  for(int i=0;i<vec.size();++i){
    if(vec[i]>n){
      cout<<vec[i-1]<<endl;
      return 0;
    }
  }
}