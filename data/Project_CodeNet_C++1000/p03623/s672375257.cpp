#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  scanf("%d%d%d", &x, &a, &b);
  cout <<(abs(x-a)>abs(x-b)? "B" : "A");
}