#include <iostream>
 
using namespace std;
 
int main () {
  int X, A, B;
  cin >> X >> A >> B;
  int Y=-1*X;
  if (0<=A-B) {
    cout << "delicious";
  }
  else if (Y<=A-B&&0>A-B) {
    cout << "safe";
  }
   else  {
     cout << "dangerous";
   }
}