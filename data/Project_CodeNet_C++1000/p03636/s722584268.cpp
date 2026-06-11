#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)

int main(){
  string str;
  cin >> str;
  
  cout << str[0] << str.size()-2 << str[str.size()-1] << endl;
}