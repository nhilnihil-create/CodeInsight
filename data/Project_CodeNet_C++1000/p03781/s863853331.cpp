#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll =long long;

int main (void) {
  int N;
  cin >> N;
  int t=0;
  do {
    t++;
  }
  while(N>(t+1)*t/2);
  cout <<t;
}