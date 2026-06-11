#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
  string O, E;
  cin >> O >> E;
  string A;
  
  for (int i = 0 ; i < ( O.length() + E.length() ) ; i++ ){
    if ( (i + 1) % 2 == 1 ){
      A.push_back(O.at( (i+1)/2 ));
    }
    else {
      A.push_back(E.at( (i+1)/2 - 1));
    }
  }


  cout << A;
}
