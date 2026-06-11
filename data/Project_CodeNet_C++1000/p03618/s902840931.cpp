#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int main() {
  string a;
  long int n, total;
  long int c[26];
  for(int k = 0; k<26; k++){
    c[k] = 0;
  }
  
  cin >> a;
  n = a.length();
  for(int i = 0; i<n; i++){
    c[a[i] - 'a']++;
  }
  total = n*(n-1)/2 +1;
  for(int j = 0; j<26; j++){
    total -= c[j]*(c[j]-1)/2;
  }
  cout << total << endl;
  return 0;
}