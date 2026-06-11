#include <iostream>
using namespace std;
     
int main() {
  int min, max, C;
  cin >> min >> max >> C;
  if(C >= min && C <= max)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}