#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B;
  cin >> A  >> B;
  
  if ( A.length() > B.length() ){
    cout << "GREATER";
  }
  if ( A.length() < B.length() ){
    cout << "LESS";
  }
  if ( A.length() == B.length() ){
    char X = 'E';
    for (int i = 0 ; i < A.length() ; i++ ){
      if (A.at(i) > B.at(i)){
        X = 'G';
        break;
      }
      else if (A.at(i) < B.at(i)){
        X = 'L';
        break;
      }
    }
    if ( X == 'G' ){
      cout << "GREATER";
    }
    else if ( X == 'L' ){
      cout << "LESS";
    }
    else if ( X == 'E' ){
      cout << "EQUAL";
    }
  }
}
