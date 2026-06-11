#include <bits/stdc++.h>
using namespace std;

int Keta(long A);

int main()
{
  long N;
  
  cin >> N;
  
  long A = 0; 
  long B = 0;
  
  int Ket = 0;
  int F = 999999;
  
  for (int i = 1; i <= 100000; i++)
  {
    if (N % i == 0) 
    {
      A = i;
      B = N / i;
      
      Ket = max(Keta(A), Keta(B));
      
      //cout << A << " " << B << " " << Ket << endl;
      
	  F = min(Ket, F);
      
    }
  }
  
  cout << F << endl;
    
}

int Keta(long A)
{
  int Ans = 1;
  for (int j = 0; j < 11; j++)
  {
    if (A / 10 != 0) 
    {
      A = A / 10;
      Ans++;
    }
  }
  
  return Ans;
}