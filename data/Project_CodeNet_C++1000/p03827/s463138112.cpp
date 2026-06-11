#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N;
  string str;
  cin >> N >> str;
  int x = 0;
  int maxX = 0; 
  for (int i = 0; i < N; i ++){
    if (str[i] == 'I'){
      x ++;
      maxX = max (maxX, x);
    } else {
      x --;
      maxX = max (maxX, x);
    }
  }
  cout << maxX << '\n';
}