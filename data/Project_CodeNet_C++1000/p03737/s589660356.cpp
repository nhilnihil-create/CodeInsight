#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

char toupr(char c) { return (c - 0x20); }

int main() {
  string A, B, C;

  cin >> A >> B >> C;

  cout << toupr(A[0]) << toupr(B[0]) << toupr(C[0]) << endl;
}
