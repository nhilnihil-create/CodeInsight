#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  int n = 0, w = 0, s = 0, e = 0;
  string x = "No";
   for (int i = 0; i < N; i++) {
     if (S.at(i) == 'N')
       n ++;
     else if (S.at(i) == 'W')
       w ++;
     else if (S.at(i) == 'S')
       s ++;
     else if (S.at(i) == 'E')
       e ++;
   }
  if (n == 0 && s == 0){
    if (w > 0 && e > 0)
      x = "Yes";
  }
  else if (w == 0 && e == 0){
    if (n > 0 && s > 0)
      x = "Yes";
  }
  else if (n > 0 && s > 0){
    if (w > 0 && e > 0)
      x = "Yes";
  }
  cout << x << endl;
}