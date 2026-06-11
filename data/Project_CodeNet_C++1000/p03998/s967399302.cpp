#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  string sa,sb,sc;
  char ch;
  cin >> sa >> sb >> sc;
  
  for(;;) {
    Loopa:
    if(sa.size() == 0) {
      cout << "A" << endl;
      return 0;
    }
    ch = sa[0];
    sa.erase(0,1);
    if(ch == 'a') goto Loopa;
    if(ch == 'b') goto Loopb;
    if(ch == 'c') goto Loopc;
  }
  for(;;) {
    Loopb:
    if(sb.size() == 0) {
      cout << "B" << endl;
      return 0; 
    }
    ch = sb[0];
    sb.erase(0,1);
    if(ch == 'a') goto Loopa;
    if(ch == 'b') goto Loopb;
    if(ch == 'c') goto Loopc;
  }
  for(;;) {
    Loopc:
    if(sc.size() == 0) {
      cout << "C" << endl;
      return 0; 
    }
    ch = sc[0];
    sc.erase(0,1);
    if(ch == 'a') goto Loopa;
    if(ch == 'b') goto Loopb;
    if(ch == 'c') goto Loopc;
  }
}