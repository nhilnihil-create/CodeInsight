#include <iostream>
using namespace std;

int main() {
  int K, S;
  cin >> K >> S;
  int count = 0;
  for (int X = 0; X <= K; X ++){
    for (int Y = 0; Y <= K; Y ++){
      for (int Z = 0; Z <= K; Z ++){
        if (X + Y + Z == S){
          count ++;
        }
      }
    }
  }
  cout << count << '\n';
}