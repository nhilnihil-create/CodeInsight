#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  
  if(a.size() > b.size()){
    cout << "GREATER" <<endl;
  }
  else if(a.size() < b.size()){
    cout << "LESS" <<endl;
  }
  else{
    for (int i=0; i<a.size(); i++){
      if (a.at(i)> b.at(i)){
        cout << "GREATER" <<endl;
        break;
      }
      else if(a.at(i)<b.at(i)){
        cout << "LESS" << endl;
        break;
      }
      else if (i == a.size()-1){
        cout << "EQUAL" <<endl;
      }
    }
  }
}
