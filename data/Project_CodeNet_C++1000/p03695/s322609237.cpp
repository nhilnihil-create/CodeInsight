#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n; cin>>n;
  map<int,int> mp;
  int max_ans=0, min_ans=0;
  rep(i,n){
    int a; cin>>a;
    if(1<=a&&a<400){
      mp[1]=1;
    }
    if(400<=a&&a<800){
      mp[2]=1;
    }
    if(800<=a&&a<1200){
      mp[3]=1;
    }
    if(1200<=a&&a<1600){
      mp[4]=1;
    }
    if(1600<=a&&a<2000){
      mp[5]=1;
    }
    if(2000<=a&&a<2400){
      mp[6]=1;
    }
    if(2400<=a&&a<2800){
      mp[7]=1;
    }
    if(2800<=a&&a<3200){
      mp[8]=1;
    }
    if(3200<=a){
      max_ans++;
    }
  }
  for(auto x : mp){
      min_ans+=x.second;
  }
  if(min_ans==0){
    min_ans=1;
  }
  
  for(auto x : mp){
    max_ans+=x.second;
  }
  cout<<min_ans<<" "<<max_ans<<endl;
}

