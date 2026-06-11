#include <bits/stdc++.h>
using namespace std;

int main(){
  string a;
  cin >> a;
  int count = 0;
  for(int i = 0; i<2; i++){
    if(a.at(i) == '9'){
      count++;
    }
  }
  if(count == 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
