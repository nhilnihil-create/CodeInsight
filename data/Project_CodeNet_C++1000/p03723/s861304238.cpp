#include<bits/stdc++.h>
using namespace std;
//原因見つかった
int main(){
  int64_t a,b,c;
  cin >> a >> b >> c;
  if(a==b&&b==c&&a%2==0&&b%2==0&&c%2==0){
    cout << -1 << endl;
  }else{
    int64_t p=0,as=a,bs=b,cs=c;
    while(a%2==0&&b%2==0&&c%2==0){
      a=bs/2+cs/2;
      b=as/2+cs/2;
      c=as/2+bs/2;
      as=a;
      bs=b;
      cs=c;
      p++;
    }
  cout << p << endl;
  }
  return 0;
}
  