#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int a, c;int b;
  cin >> a >> b >> c; //>> b >> c;
  double ans, ra, rb;
  string dolphinManJotaro;
  if(a != b && b != c && a != c){
    cout << 3;
  }else if(a == b && b == c){
    cout << 1;
  }else{
    cout << 2;
  }
  return 0;
}
