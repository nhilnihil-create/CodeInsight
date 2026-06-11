#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> s(100,1000);
  int sum=0;
  rep(i,n){
    cin>>s[i];
    sum+=s[i];
  }
  
  sort(s.begin(),s.end());
  
  
  
  if(sum%10==0){
    int a=sum;
    rep(i,n){if(s[i]%10 !=0){
      a=s[i];
      break;
    }
            }
    cout<<sum-a<<endl;
  }
  else{cout<<sum<<endl;
      }
    
        
  
}