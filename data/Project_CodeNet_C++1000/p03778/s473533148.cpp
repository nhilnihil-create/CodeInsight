#include <bits/stdc++.h>
#define PI 3.1415926535897932
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int W,a,b;
  cin>>W>>a>>b;
  
  int ans=0;
  
  
  if(b>a+W){
    ans=b-(a+W);
  }
  else if(b+W<a){
    ans=a-(b+W);
  }
  
  cout<<ans<<endl;
}
