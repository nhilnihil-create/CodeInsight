#include <iostream>
 
const int MAX_W = 505;
const int MAX = 1e9;
 
using namespace std;
 
int table [MAX_W][MAX_W];
 
int main () {
  int largeh, largew, smallh, smallw;
  cin >> largeh >> largew >> smallh >> smallw;

  if (smallh * smallw == 1) {
    cout << "No" << endl;
    return 0;
  }

  int amb = (MAX - 1) / (smallh * smallw - 1);
  int neg = -(smallh * smallw - 1) * amb - 1;
 
  long long sum = 0;
  for (int i = 1; i <= largeh; i++) {
    for (int j = 1; j <= largew; j++) {
      if (i % smallh == 0 &&
          j % smallw == 0) {
        table[i][j] = neg;
      } else {
        table[i][j] = amb;
      }
 
      sum += table[i][j];
    }
  }
 
  if (sum > 0) {
    cout << "Yes" << endl;
    for (int i = 1; i <= largeh; i++) {
      for (int j = 1; j <= largew; j++) {
        cout << table[i][j] << " ";
      }
      cout << endl;
    }
  } else {
    cout << "No" << endl;
  }
}
