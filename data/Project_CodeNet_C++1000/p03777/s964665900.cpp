#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string a, b;
  cin >> a >> b;

  if ((a == "H" && b == "H") || (a == "D" && b == "D")){
    cout << "H" << endl;
  }
  else
  {
    cout << "D" << endl;
  }
  
}