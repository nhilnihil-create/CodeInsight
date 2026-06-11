#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(min(b,d)-max(a,c) < 0){
    cout << 0 << endl;
  }
  else{
    cout << min(b,d)-max(a,c) << endl;
  }
}