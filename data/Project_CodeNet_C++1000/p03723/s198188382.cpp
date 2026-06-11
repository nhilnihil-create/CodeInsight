#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int A,B,C;
  cin>>A>>B>>C;
  
  if(A==B&&B==C&&A%2==0){
    cout<<-1<<endl;
  }
  else{
  int ans=0;
  
  while(true){
    if(A%2==1||B%2==1||C%2==1){
      break;
    }
    int a=A/2;
    int b=B/2;
    int c=C/2;
    
    A=a+b;
    B=b+c;
    C=c+a;
    
    ans++;
  }
  
  cout<<ans<<endl;
  }
}