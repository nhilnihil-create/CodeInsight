#include <bits/stdc++.h>
using namespace std;
int main (){
  long long A,B,C;
  cin >>A>>B>>C;
  
  int ans=0;
  
  if (A%2==1 || B%2==1 | C%2==1){
    cout << 0 << endl;
  }
  else if (A==B && B==C){
    cout << -1 << endl;
  }
  else{
  while(A%2==0 && B%2==0 && C%2==0){
    int a=A/2;
    int b=B/2;
    int c=C/2;
    A=b+c;
    B=c+a;
    C=a+b;
    ans++;
  }
    cout << ans << endl;
  }

}