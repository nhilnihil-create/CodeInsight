#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B, x=0, y=0;
  string S;
  cin >> N >> A >> B;
  cin >> S;
  for (int i = 0; i < N; i++)
  {
    if (S.at(i) == 'a' && x+y < A+B)
    {
      cout << "Yes" << endl;
      x++;
    }else if (S.at(i) == 'b' && x+y < A+B && y < B)
    {
      cout << "Yes" << endl;
      y++;
    }else
    {
      cout << "No" << endl;
    }
    
  }
  
  return 0;
}