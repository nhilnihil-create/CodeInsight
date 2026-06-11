#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a[1000000];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int num=0;
  map<long long,int>mp;
  for(int i=0;i<n;i++){
      mp[a[i]]++;
  }
  for(auto i:mp){
      if(i.second%2!=0){
          num++;
      }
  }
  cout<<num<<endl;
}
      
