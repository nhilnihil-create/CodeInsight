#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A,B,C;
  cin >> A >> B >> C;
  int check = A;
  int flag = 0;
  do
  {
    if(check%B == C) 
    {
      flag = 1;
      break;
    }
    check = (check+A)%B;
  }while(check%B != A%B && flag == 0);
  
  if(flag == 1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}
