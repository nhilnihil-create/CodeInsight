#include <bits/stdc++.h>
using namespace std;

int main() {
  string w;
  cin >> w;
  int count;
  count = 0;
  for  (int i=0; i<w.size(); i++){
    for (int j=0; j<w.size(); j++){
      if (w.at(i)==w.at(j)){
        count++;
      }
    }
    if (count%2==1){
      break;
    }
    count = 0;
  }
  if (count!=0){
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}