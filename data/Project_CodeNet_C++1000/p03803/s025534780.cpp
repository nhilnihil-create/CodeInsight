#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  a=(a+11)%13;
  b=(b+11)%13;
  if(a>b){
    cout << "Alice" << endl;
  }else if(a<b){
    cout << "Bob" << endl;
  }else{
    cout << "Draw" << endl;
  }
}