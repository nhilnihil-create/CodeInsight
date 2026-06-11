#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a = 0;
  for (int i=1; i < n+1; i++) {
    a += i; 
  }
  cout << a;
}