#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,tmpa,tmpb;
  cin >> a >> b >> c;

  int ans=0;
  bool flag=true;
  while(flag){
    if(a%2!=0 || b%2!=0 || c%2!=0)break;
    if(a==b && b==c){
      cout << -1 << endl;
      return 0;
    }
    tmpa=a;
    tmpb=b;
    a=b/2+c/2;
    b=tmpa/2+c/2;
    c=tmpa/2+tmpb/2;
    ans++;
  }
  cout << ans << endl;
}
