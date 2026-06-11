#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long n, long long root)	{
  for (long long i = 2; i <= root; i++)	{
    if (n % i == 0)
      return false;
  }
  return true;
}

int nDigits(long long n)	{
  int digits = 0;
  while (n > 0)	{
    digits++;
    n /= 10;
  }
  return digits;
}

int main()	{
  long long n;
  cin >> n;
  long long root = sqrt(n);
  //cout << root << endl;
  if (isPrime(n, root))	{
    cout << nDigits(n) << endl;
  }
  else	{
    //find largest factor starting from sqrt(n)
    for (long long i = root; i < n; i++)	{
      if (n % i == 0)	{
        cout << nDigits(i) << endl;
		return 0;
      }
    }
  }
  return 0;
}