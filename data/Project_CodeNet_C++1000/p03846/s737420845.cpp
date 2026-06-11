#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)


int main() {
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(100010);
  rep(i,n){
    cin>>a.at(i);
    b.at(a.at(i))++;
  }
  bool ch=true;
  rep(i,n){
    if(n%2==0){
      if(i%2==0){
        if(b.at(i)!=0){
          ch=false;
        }
      }
      else{
        if(b.at(i)!=2){
           ch=false;
        }
      }
    }
    else{
      if(i==0){
        if(b.at(i)!=1){
          ch=false;
        }
      }
      else if(i%2==0){
        if(b.at(i)!=2){
          ch=false;
        }
      }
      else{     
        if(b.at(i)!=0){
          ch=false;
        }
      }
    }
  }
  long ans=1;
  int c=n/2;
  while(c--){
    ans*=2LL;
    ans%=1000000007;
  }
    
    
  if(ch){
    cout<<ans<<endl;
  }
  else{
    cout<<0<<endl;
  }
 
}