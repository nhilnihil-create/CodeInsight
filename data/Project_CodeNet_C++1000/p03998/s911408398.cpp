#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

int main() {
  string p[3];
  char men[3] = {'A', 'B', 'C'};
  int idx[3] = {};
  for (int i=0; i<3; i++) cin >> p[i];
  int who = 0;
  while(1) {
    if ((int)p[who].length() == idx[who]) {cout << men[who] << endl; return 0;}
    idx[who]++;
    who = p[who][idx[who]-1] - 'a';
    //while(p[i].length() > idx[i] && p[i][idx[i]-1] == men[i]+32) idx[i]++;
    //cout << men[i] << " " << idx[i] << endl;
    //if ((int)p[i].length() == idx[i]) {cout << men[i] << endl; return 0;}
  }
  return 0;
}
