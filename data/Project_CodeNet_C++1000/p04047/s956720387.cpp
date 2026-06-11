#include <bits/stdc++.h>
using namespace std;


int main() {
  long long n; cin >> n;
  vector<long long> kusi(2*n);
  
  for(int i=0; i < 2*n; i++){
    long long x; cin >> x;
    kusi.at(i) = x;
  }
  
  sort(kusi.begin(),kusi.end());
  
  long long sum; sum = 0;
  
  for(int i=0; i < n; i++){
    sum += min(kusi.at(2*i),kusi.at(2*i+1));
  }
  
  cout << sum << endl;
}
