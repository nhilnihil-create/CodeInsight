#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  bool result = true;
  if(c < a) result = false;
  if(c > b) result = false;
  if(result){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}