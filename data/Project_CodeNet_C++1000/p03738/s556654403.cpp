#include <bits/stdc++.h>
using namespace std;
int main()
  {string A, B; cin >> A >> B;
  cout << (A == B ? "EQUAL" : vector<string>{"GREATER", "LESS"}[A.size() == B.size() ? A < B : A.size() < B.size()]);}