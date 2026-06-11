#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n){
    cin>>a.at(i);
  }
  long c=0;
  long ans=0;
  bool ch=true;
  long co=0;
  if(a.at(0)!=0){
  rep(i,n){
    if(ch){
      if(co+a.at(i)>=0){
        c+=co+a.at(i)+1;
        co=-1;
      }
      else{
        co+=a.at(i);
      }
      ch=false;
    }
    else{
      if(co+a.at(i)<=0){
        c+=1-co-a.at(i);
        co=1;
      }
      else{
        co+=a.at(i);
      }
      ch=true;
    }
   }
    ch=false;
    co=0;
  rep(i,n){
    if(ch){
      if(co+a.at(i)>=0){
        ans+=co+a.at(i)+1;
        co=-1;
      }
      else{
        co+=a.at(i);
      }
      ch=false;
    }
    else{
      if(co+a.at(i)<=0){
        ans+=1-co-a.at(i);
        co=1;
      }
      else{
        co+=a.at(i);
      }
      ch=true;
    }
  }
    ans=min(ans,c);
    cout<<ans<<endl;
  }
  else{
    
   rep(i,n){
    if(ch){
      if(co+a.at(i)>=0){
        c+=co+a.at(i)+1;
        co=-1;
      }
      else{
        co+=a.at(i);
      }
      ch=false;
    }
    else{
      if(co+a.at(i)<=0){
        c+=1-co-a.at(i);
        co=1;
      }
      else{
        co+=a.at(i);
      }
      ch=true;
    }
   }
    ch=false;
    co=0;
    rep(i,n){
    if(ch){
      if(co+a.at(i)>=0){
        ans+=co+a.at(i)+1;
        co=-1;
      }
      else{
        co+=a.at(i);
      }
      ch=false;
    }
    else{
      if(co+a.at(i)<=0){
        ans+=1-co-a.at(i);
        co=1;
      }
      else{
        co+=a.at(i);
      }
      ch=true;
    }
  }
    ans=min(ans,c);
    cout<<ans<<endl;
  }  
}