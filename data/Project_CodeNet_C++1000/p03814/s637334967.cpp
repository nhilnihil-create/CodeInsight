#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int apos = s.find_first_of("A");
  int zpos = s.find_last_of("Z");
  cout << zpos - apos + 1 << endl;
}