#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll n; cin>>n;
  vector<int> v(n);
  rep(i,n){cin>>v[i];}
  sort(v.begin(),v.end());
  int a=0,b=0,c=0;
  int i=0,ans;
  if(v[n-1]-v[0]<2){ans=n;}
  else{
    while(i<n){
      if(v[i]==v[0]){a++;i++;}
      else{break;}
    }
    while(i<n){
      if(v[i]==v[0]+1){b++;i++;}
      else{break;}
    }
    while(i<n){
      if(v[i]==v[0]+2){c++;i++;}
      else{break;}
    }
    ans=a+b+c; 
    rep(j,v[n-1]-v[0]-1){
      a=b; b=c; c=0;
      while(i<n){
        if(v[i]==v[0]+j+3){c++;i++;}
        else{break;}
      }
      
      ans=max(ans,a+b+c);
    }
  }
  cout<<ans;
} 