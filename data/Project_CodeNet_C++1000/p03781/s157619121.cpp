#include<bits/stdc++.h>
using namespace std;
int main() {
  long long X; cin >> X;
  long long t = 0;
  while (t * (t+1) / 2 < X) t++;
  cout << t << '\n';
}