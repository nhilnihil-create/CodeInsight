#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,T;
  cin >> K >> T;
  vector<int> a(T);
  for(int i=0;i<T;i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end(),greater<int>());
  cout << max(a.front()-1-(K-a.front()),0) << endl;
  return 0;
}
