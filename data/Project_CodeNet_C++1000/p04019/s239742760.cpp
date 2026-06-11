#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  vector<int> dir(4);
  for(int i = 0; i < (int)s.size(); i++){
    if(s.at(i) == 'N') dir.at(0) = 1;
    else if(s.at(i) == 'W') dir.at(1) = 1;
    else if(s.at(i) == 'S') dir.at(2) = 1;
    else dir.at(3) = 1;
  }
  
  bool ok = true;
  if(dir.at(0) ^ dir.at(2)) ok = false;
  if(dir.at(1) ^ dir.at(3)) ok = false;
  
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}