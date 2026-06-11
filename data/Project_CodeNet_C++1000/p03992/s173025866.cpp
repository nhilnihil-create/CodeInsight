#include <bits/stdc++.h>

using namespace std;

int main() {

  

  string s,t;
  cin >> s;
  
  for (int i=0 ;i<4;i++){
    t= t+s.at(i);
   }
  t = t+ ' ';
  for(int i =4;i<12;i++){
    t=t+s.at(i);
    }
  cout << t<< endl;

  }

