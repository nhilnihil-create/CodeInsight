#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string A, B;
  cin >> A>> B;

  

  if (A.size() > B.size()){
    cout << "GREATER" << endl;
  }
  else if (A.size() == B.size())
  {
    for (int i = 0; i < A.size(); i++)
    {
      if (A.at(i) > B.at(i)){
        cout << "GREATER" << endl;
        return 0;
      }
      else if (A.at(i) == B.at(i) && i == A.size() - 1)
      {
        cout << "EQUAL" << endl;
        
      }
      else if (A.at(i) < B.at(i))
      {
        cout << "LESS" << endl;
        return 0;
      }
      
      
    }
    
  }
  else
  {
    cout << "LESS" << endl;
  }

  
}