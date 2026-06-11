#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b; cin >> a >> b;
  if(b==0) {
    cout << "Zero" << endl;  
  } else if(b>0) {
    cout << ( a<=0 ? "Zero" : "Positive" ) << endl;  
  } else {
    cout << ( (b-a+1)%2==0 ? "Positive" : "Negative" ) << endl;
  }
  return 0;
}