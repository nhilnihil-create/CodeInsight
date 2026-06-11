#include <iostream>
using namespace std;
void take_primes(int arr[], int &n)
{
  int tmp, div;
  for(int i = 1; i <= n; i++)
  {
    tmp = i;
    div = 2;
    while( tmp > 1 )
      if( tmp % div == 0 ){
        tmp /= div;
        arr[div-2]++;
      }
      else
        div++;
  }
}
int main()
{
  int n;
  long long int ans = 1, mod = 1000000007;
  cin >> n;
  int arr[1000]{};
  take_primes(arr,n);
  for(int i = 0; i < n-1; i++)
  {
    ans *= (arr[i] + 1);
    ans %= mod;
  }
  cout << ans;
}
  
  
  