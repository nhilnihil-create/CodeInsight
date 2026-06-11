#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  if(a==b&&b==c&&a%2==0)cout << -1;
  else{
    int i=0,p,q,r;
    while(a%2==0&&b%2==0&&c%2==0){
      p=a;
      q=b;
      r=c;
      a=(q+r)/2;
      b=(p+r)/2;
      c=(p+q)/2;
      i++;
    }
    cout << i;
  }
  cout << endl;
}
