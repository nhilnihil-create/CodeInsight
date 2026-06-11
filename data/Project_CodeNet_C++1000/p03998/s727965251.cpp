#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string sa,sb,sc;
  cin >> sa >> sb >> sc;
  
  char ch = 'a';
  for(; ;) {
    switch(ch) {
      case 'a': 
        if(sa.size() == 0) {
          cout << "A" << endl;
          return 0;
        }
        else {
          ch = sa[0];
          sa.erase(0,1);
          break;
        }
      case 'b': 
        if(sb.size() == 0) {
          cout << "B" << endl;
          return 0;
        }
        else {
          ch = sb[0];
          sb.erase(0,1);
          break;
        }
      case 'c': 
        if(sc.size() == 0) {
          cout << "C" << endl;
          return 0;
        }
        else {
          ch = sc[0];
          sc.erase(0,1);
          break;
        }
    }
  }
}