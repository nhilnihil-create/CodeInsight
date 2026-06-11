#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  if (N%10 == 9 || N%100 >= 90){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
    

