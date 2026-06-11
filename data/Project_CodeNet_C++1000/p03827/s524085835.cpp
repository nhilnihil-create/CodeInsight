#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  vector<int> a(N+1);
  a.at(0)=0;
  for (int i=0; i<N; i++) {
    if (S.at(i)=='I') {
      a.at(i+1)=a.at(i)+1;
    }
    else {
      a.at(i+1)=a.at(i)-1;
    }
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  cout << a.at(0) << endl;
}