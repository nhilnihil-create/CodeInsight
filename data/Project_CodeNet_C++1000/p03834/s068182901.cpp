#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < 19; i++){
    if(s.at(i) == ','){
     s.at(i) = ' '; 
    }
  }
  cout << s << endl;
}
