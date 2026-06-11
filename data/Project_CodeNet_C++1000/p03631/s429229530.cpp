#include <bits/stdc++.h>
using namespace std;

int main() {
  int a ;
  cin >> a ;
  cout << (((a-a%100)/100)==(a%10) ? "Yes" : "No")
    << endl;
}