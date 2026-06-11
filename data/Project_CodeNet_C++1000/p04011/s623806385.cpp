#include <iostream>
using namespace std;

int main()
{
  int total = 0,  n = 0, k = 0, x = 0, y = 0;
  int last = 0;
  
  cin >> n >> k >> x >> y;
  if(n<=k)
  {
  	total=(n*x);
  }
  if(n>k)
  {
    last = n-k;
  	total += (k*x) + y*last;
  }
  cout << total;
}