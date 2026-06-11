#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int a,b;
  cin>>a>>b;  
  if(a==0||b==0){
    if(b>a){
      cout<<abs(b-a)<<endl;
    }
    else{
      cout<<abs(b-a)+1<<endl;
    }
  }
  else{
  if((a<b&&b<0)||(a<b&&a>0)){
    cout<<b-a<<endl;
  }
  else if((a<0&&b>0)||(a>0&&b<0)){
    cout<<abs(abs(b)-abs(a))+1<<endl;
  }
  else{
    cout<<abs(b-a)+2<<endl;
  }
  }
 
}