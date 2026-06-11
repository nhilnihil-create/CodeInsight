#include <iostream>

using namespace std;

int main() {

  int a, b;
  cin >> a >> b;
  if(a <= 0 && 0 <= b){
    cout << "Zero";
  }else if(1 <= a){
    cout << "Positive";
  }else{
    if((abs(b) - abs(a) + 1) % 2 == 0){
      cout << "Positive";
    }else{
      cout << "Negative";
    }
  }
  return 0;
}
