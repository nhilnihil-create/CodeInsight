#include <iostream>
#define ll long long
using namespace std;

int main() {
  ll a, b;
  cin >> a >> b;

  //a && b > 0
  if (a > 0 && b > 0){
    cout << "Positive" << endl;
    return 0;
  }
  //a && b or a or b == 0
  if (a == 0 || b == 0 || (a < 0 && b > 0)){
    cout << "Zero" << endl;
    return 0;
  }
  //a & b < 0
  if (a < 0 && b < 0){
    a = a*(-1);
    b = b*(-1);
    ll ab = a-b;
    if (ab%2 == 0){
      cout << "Negative" << endl;
      return 0;
    }
    cout << "Positive" << endl;
  }

  return 0;
}