#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int i = 1;
  while(true)
  {
    if(N < i) break;
    i *= 2;
  }
  
  cout << i / 2 << endl;
}