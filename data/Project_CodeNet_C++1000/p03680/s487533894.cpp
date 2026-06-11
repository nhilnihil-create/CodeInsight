//#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int a[N];
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int x[N];
  for(int i = 0; i < N; i++) {
    x[i] = 0;
  }
  
  int now = 0;
  int i = 0;
  while(x[now] == 0) {
    i++;
    x[now] = 1;
    now = a[now] - 1;
    if(now == 1) {
      cout << i << endl;
      break;
    }
  }
  if(now != 1) {
    cout << -1 << endl;
  }
}
