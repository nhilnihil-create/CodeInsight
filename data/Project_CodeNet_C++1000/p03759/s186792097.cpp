#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  
  cin >> a >> b >> c;
  
  if(b-a == c-b){
      cout << "YES";
      return 0;
  }
  cout << "NO";
  
  return 0;
}
