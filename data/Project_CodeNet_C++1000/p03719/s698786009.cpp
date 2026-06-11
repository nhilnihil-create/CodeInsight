#include <bits/stdc++.h>
using namespace std;

int main(){
  int lower,upper,X;
  cin >> lower >> upper >> X;

  string ans= (lower <= X && X <= upper) ? "Yes"
                                         : "No";

  cout << ans << endl;
}