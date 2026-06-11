#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N=s.size();
  int i=0;
  int a_min;
  while(true){
    if (s.at(i) == 'A'){
      a_min = i;
      break;
    }
    else
      i++;
  }
  i=N-1;
  int z_max;
  while(true){
    if(s.at(i) == 'Z'){
      z_max = i;
      break;
    }
    else
      i--;
  }
  cout << z_max-a_min+1 << endl;
}