#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> p(124,0);
  string s;
  cin >> s ;
  for ( int i=0 ; i<s.size() ; i++){
    p[(int)(s.at(i))]++;
}
  for ( int i=0 ; i<125 ; i++){
    if (p[i]>=2){
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
}