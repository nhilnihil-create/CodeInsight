#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int L,N;
  cin >> N >> L;
  string s[200];
  for(int i = 0; i < N; i++)
    cin >> s[i];

  sort(s,s+N);
  for(int i = 0; i < N; i++)
    cout << s[i];
  cout << endl;
}