#include<iostream>
using namespace std;

int main(){
  int w,a,b,ans;
  cin >> w >> a >> b;

  if(a>b){
    ans=a-b-w;
  }
  else{
    ans=b-a-w;
  }
    if(ans>0){
      cout << ans << endl;
    }
    else{
      cout << "0" << endl;
    }
}
