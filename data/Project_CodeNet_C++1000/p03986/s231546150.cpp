#include <iostream>
#include <string>
using namespace std;

int main() {
  string X;
  cin >> X;
  int N = X.size();
  
  int S = 0;
  int count = 0;
  for (int i = 0; i < N; i++){
    if (X[i] == 'S'){
      S++;
    }
    if (X[i] == 'T'){
      if (S > 0){
        count++;
        S--;
      }
    }
  }
  
  cout << N - 2 * count;
}