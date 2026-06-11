#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  vector<int> a(3);
  
  for(int i = 0; i < 3; i++){
    a.at(i) = n % 10;
    n /= 10;
  }
  
  if ( a.at(0) == a.at(2) ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  
  
  
}

