#include <bits/stdc++.h>
using namespace std;

int main(void){
  
  string s;
  cin >> s;
  int aPos = s.find_first_of('A');
  int last_z_pos = s.find_last_of('Z');
  cout << last_z_pos - aPos + 1 << endl;
}
