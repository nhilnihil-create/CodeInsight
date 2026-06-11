#include <bits/stdc++.h>
using namespace std;

int main () {
  int K,T;
  cin >> K >> T;
  
  if (T == 1){
    cout << K-1 << endl;
    return 0;
  }
  
  vector<int>a(T);
  for (int i = 0; i < T; i++) {
    cin >> a.at(i);
  }
  
  sort(a.begin(), a.end()); 
  int A = a.at(T-1);
  int half = (K+1)/2;
  
  if (T != 1){
    if (A <= half){
      cout << 0 << endl;
      return 0;
    }
    else {
      cout << a.at(T-1)-(K-a.at(T-1))-1 << endl;
      return 0;
    }
  }
}
  
  

  
  
  
 
  
  