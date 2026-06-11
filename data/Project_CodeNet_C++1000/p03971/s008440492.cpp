#include <iostream>
#include <string>
using namespace std;

int main()
{
  int N, A, B;
  string S;
  cin >> N >> A >> B;
  cin >> S;
  
  int a = 0;
  int b = 0;
  
  for(int i = 0; i < N; ++i)
  {
    if(S[i] == 'a')
    {
      if(a+b<A+B)
      {
        cout << "Yes" << endl;
        a++;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    else if(S[i] == 'b')
    {
      if(a+b<A+B && b+1<=B)
      {
        cout << "Yes" << endl;
        b++;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    else if(S[i] == 'c')
    {
      cout << "No" << endl;
    }
  }
}