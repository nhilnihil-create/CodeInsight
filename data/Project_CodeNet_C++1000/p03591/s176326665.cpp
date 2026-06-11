#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  
  string T = "YAKI";
  
  if(equal(T.begin(), T.end(), S.begin()))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}