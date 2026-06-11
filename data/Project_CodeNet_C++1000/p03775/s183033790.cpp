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
  int64_t N, B=1;
  cin >> N;
  for (int64_t A=1; A<=sqrt(N); A++) {
    if (N%A==0) {
      B=N/A;
    }
  }
  if (B<10) {
    cout << 1 << endl;
  }
  else if (B<100) {
    cout << 2 << endl;
  }
  else if (B<1000) {
    cout << 3 << endl;
  }
  else if (B<10000) {
    cout << 4 << endl;
  }
  else if (B<100000) {
    cout << 5 << endl;
  }
  else if (B<1000000) {
    cout << 6 << endl;
  }
  else if (B<10000000) {
    cout << 7 << endl;
  }
  else if (B<100000000) {
    cout << 8 << endl;
  }
  else if (B<1000000000) {
    cout << 9 << endl;
  }
  else if (B<10000000000) {
    cout << 10 << endl;
  }
}