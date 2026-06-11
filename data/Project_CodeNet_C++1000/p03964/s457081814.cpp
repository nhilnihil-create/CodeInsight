#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> t(n), a(n);
  for(int i = 0; i < n; i++) cin >> t.at(i) >> a.at(i);
  
  long long ta = 1;
  long long ao = 1;
  for(int i = 0; i < n; i++){
    long long k = max((t.at(i) - 1 + ta) / t.at(i), (a.at(i) - 1 + ao) / a.at(i));
    ta = t.at(i) * k;
    ao = a.at(i) * k;
  }
  
  cout << ta + ao << endl;
}