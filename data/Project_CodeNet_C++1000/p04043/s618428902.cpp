#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  
  vector<int> a = {A,B,C};
  
  int five = 0;
  int seven = 0;
  for(int i = 0; i < 3; i++){
    if(a.at(i) == 5){
      five++;
    }
    else if(a.at(i) == 7){
      seven++;
    }
  }
  
  if(five == 2 && seven == 1){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
    return 0;
}