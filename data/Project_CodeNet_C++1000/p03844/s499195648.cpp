#include<iostream>
using namespace std;

int main(){
      int a,b; int ans;
      string op;
      cin>>a>>op>>b;
      if( op =="+") ans = a+b;
      else  if( op =="-") ans = a-b;
        cout<<ans;
        return 0;
}
      
