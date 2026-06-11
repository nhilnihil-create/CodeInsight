#include <iostream>
using namespace std;
int main()
{
  int n, x, sum = 0, tmp;
  cin >> n;
  int arr[100000]{};
  for(int i = 0; i < n; i++)
  {
    cin >> x;
    arr[x-1]++;
    if( arr[x-1] > 1 )
      sum++;
  }
  tmp = sum/2;
  tmp *= 2;
  if( sum - tmp == 1 )
    sum++;
  cout << n - sum;
}