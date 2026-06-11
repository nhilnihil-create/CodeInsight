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
  int N, hai=0, cha=0, midori=0, mizu=0, ao=0, ki=0, daidai=0, aka=0, kin=0, c=0;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
    if (a[i]<400) {
      hai=hai+1;
    }
    else if (a[i]<800) {
      cha=cha+1;
    }
    else if (a[i]<1200) {
      midori=midori+1;
    }
    else if (a[i]<1600) {
      mizu=mizu+1;
    }
    else if (a[i]<2000) {
      ao=ao+1;
    }
    else if (a[i]<2400) {
      ki=ki+1;
    }
    else if (a[i]<2800) {
      daidai=daidai+1;
    }
    else if (a[i]<3200) {
      aka=aka+1;
    }
    else {
      kin=kin+1;
    }
  }
  if (hai>0) {
    c=c+1;
  }
  if (cha>0) {
    c=c+1;
  }
  if (midori>0) {
    c=c+1;
  }
  if (mizu>0) {
    c=c+1;
  }
  if (ao>0) {
    c=c+1;
  }
  if (ki>0) {
    c=c+1;
  }
  if (daidai>0) {
    c=c+1;
  }
  if (aka>0) {
    c=c+1;
  }
  cout << max(c,1) << " " << c+kin << endl;
}