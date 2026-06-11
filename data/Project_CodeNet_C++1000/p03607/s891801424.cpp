#include<bits/stdc++.h>
using namespace std;
int main(){
  map<int,int>a;
  int n;cin>>n;
  int tmp;
  for(int i=0;i<n;i++){
    cin>>tmp;
    if(a.count(tmp)){
      if(a.at(tmp)==0){
        a.at(tmp)++;
      }
      else{
        a.at(tmp)--;
      }
    }
    else{
      a[tmp]=1;
    }
  }
  int ans=0;
  for(auto num:a){
    ans+=num.second;
  }
  cout <<ans<<endl;
}