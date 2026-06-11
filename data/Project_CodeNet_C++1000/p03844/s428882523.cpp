#include<bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  char op;
  cin >> A >> op >> B;
  cout << A + (op == '-' ? -B : B) << "\n";
}