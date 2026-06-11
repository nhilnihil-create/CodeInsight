#include<iostream>
using namespace std;
int main()
{
  int n, a, b;
  cin >> n;
  a = n / 100;
  b = n % 10;
  if(a == b)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}