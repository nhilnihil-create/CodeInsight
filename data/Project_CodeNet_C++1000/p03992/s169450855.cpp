#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, t, u;
  cin >> s;
  for(int i = 0; i <4; i++){
    t += s.at(i);
    u += s.at(i*2+4);
    u += s.at(i*2+5);
  }
  cout << t << ' ' << u << endl;
}
