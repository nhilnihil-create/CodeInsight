#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N, n, w, s, e;
  N=S.size();
  n=0;
  w=0;
  s=0;
  e=0;
  for (int i=0; i<N; i++) {
    if (S[i]=='N') {
      n=n+1;
    }
    else {
      if (S[i]=='W') {
        w=w+1;
      }
      else {
        if (S[i]=='S') {
          s=s+1;
        }
        else {
          e=e+1;
        }
      }
    }
  }
  if (n==0 && s==0) {
    if (w!=0 && e!=0) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    if (n==0||s==0) {
      cout << "No" << endl;
    }
    else {
      if (w==0 && e==0) {
        cout << "Yes" << endl;
      }
      else {
        if (w==0||e==0) {
          cout << "No" << endl;
        }
        else {
          cout << "Yes" << endl;
        }
      }
    }
  }
}