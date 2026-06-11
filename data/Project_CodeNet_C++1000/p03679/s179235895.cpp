#include <bits/stdc++.h>
using namespace std;

int main(){
  int addtional, regulation, T;
  cin >> addtional >> regulation >> T;

  string ans= (T <= regulation           ) ? "delicious"
             :(T <= regulation+ addtional) ? "safe"
                                           : "dangerous";
  cout << ans << endl;
}
