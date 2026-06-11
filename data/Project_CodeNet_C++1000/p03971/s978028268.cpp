#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int N, A, B, Pa=0, Pb=0;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  for (int i=0; i<N; i++) {
    if (S[i]=='a') {
      if (Pa<A+B) {
        cout << "Yes" << endl;
        Pa=Pa+1;
      }
      else {
        cout << "No" << endl;
      }
    }
    else if (S[i]=='b') {
      if (Pa<A+B && Pb<B) {
        cout << "Yes" << endl;
        Pa=Pa+1;
        Pb=Pb+1;
      }
      else {
        cout << "No" << endl;
      }
    }
    else {
      cout << "No" << endl;
    }
  }
}