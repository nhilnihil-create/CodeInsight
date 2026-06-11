#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  long n;
  cin >> n;

  long mi = 10000000000;
  long an;
  for(string a = "1"; stoi(a) <= sqrt(n); an++,
  a = to_string(an)) {
    an = stoi(a);
    long bn = n/an;
    string b = to_string(bn);
    if(bn != double(n)/an) continue;
    long f = max(a.size(),b.size());
    mi = min(mi,f);
    
  }
  
  cout << mi << endl;
  return 0;
}