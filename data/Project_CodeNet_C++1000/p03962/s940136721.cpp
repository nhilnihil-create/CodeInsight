#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  int count = 1;
  cin >> a >> b >> c;
  if (a != b) count++;
  if (a != c) count++;
  if (b == c) count--;
  if (count == 0) count++;
  cout << count << endl;    
}
