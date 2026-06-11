#include<iostream>
using namespace std;
int main()
{
  int w, a, b;
  cin >> w >> a >> b;
  if(a + w < b)
    cout << b - a - w;
  if((a + w >= b && a + w <= b + w) || (b + w >= a && b + w <= a + w))
    cout << 0;
  if(b + w < a)
    cout << a - b - w;
    return 0;
}
