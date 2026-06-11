#include <iostream>
using namespace std;

int a;
int b;

int main(){
  cin >> a >> b;
  if(a <= 0 && b >= 0){
    cout << "Zero";
  }
  else if(a < 0 && b < 0){
    if((b - a + 1) % 2 == 0){
      cout << "Positive";
    }
    else {
      cout << "Negative";
    }
  }
  else if(a > 0 && b > 0){
    cout << "Positive";
  }
}