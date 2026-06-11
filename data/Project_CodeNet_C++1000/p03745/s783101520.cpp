#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,a[200000];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  int mark;
  if(a[0] < a[1]) mark = 0;
  if(a[0] > a[1]) mark = 1;
  if(a[0] == a[1]) mark = 2;
  
  int cnt = 1;
  for(int i = 1; i < n-1; i++) {
    if(mark == -1) {
      if(a[i] < a[i+1]) mark = 0;
      if(a[i] > a[i+1]) mark = 1;
      if(a[i] == a[i+1]) mark = 2;
    }
    if(mark == 0) {
      if(a[i] > a[i+1]) {
        cnt++; mark = -1; 
      }
    }
    if(mark == 1) {
      if(a[i] < a[i+1]) {
        cnt++; mark = -1; 
      }
    }
    if(mark == 2) mark = -1;
  }
  cout << cnt << endl;
  return 0;
}