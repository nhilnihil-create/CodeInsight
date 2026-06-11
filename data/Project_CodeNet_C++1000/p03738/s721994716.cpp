#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  if (A.size()>B.size())
    cout << "GREATER" << endl;
  else if (A.size()<B.size())
    cout << "LESS" << endl;
  else{
    bool eq = true;
    int i=0;
    while (eq){
      if (A.at(i) > B.at(i)){
        eq = false;
        cout << "GREATER" << endl;
      }
      else if (A.at(i) < B.at(i)){
        eq = false;
        cout << "LESS" << endl;
      }
      else if (A.at(i) == B.at(i) && i==A.size()-1){
        eq = false;
        cout << "EQUAL" << endl;
      }
      i++;
    }
  }
}