#include<iostream>
using namespace std;

int main() {
  long A, B, X; cin >> A >> B >> X;
  cout << (B/X - (A+X-1)/X + 1);
}