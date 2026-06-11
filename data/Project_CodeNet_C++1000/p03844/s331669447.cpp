#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A , C ;
  char B;
  cin >> A >> B >> C;
  if ( B == '+' ){
    cout << A+C << endl;
  }else if ( B == '-' ){
    cout << A-C << endl;
  }
}