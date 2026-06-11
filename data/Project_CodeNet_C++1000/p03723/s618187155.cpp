#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int ans=0;
  while(1){
    if(a==b && b==c){
      if(a%2==0){
        cout<<-1<<endl;
        break;
      }
      else{
        cout<<ans<<endl;
        break;
      }
    }
    else{
      int x=b+c;
      int y=c+a;
      int z=a+b;
      if((x%2==0 && y%2==0) && z%2==0){
        a=x/2;
        b=y/2;
        c=z/2;
        ans++;
      }
      else {
        cout<<ans<<endl;
        break;
      }
    }
  }
}
