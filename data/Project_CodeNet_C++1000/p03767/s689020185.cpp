#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<long long> a(3*N); 
  for(int i=0;i<3*N;i++){
    cin >> a.at(i);
  }
  
  sort(a.begin(),a.end(),greater<int>());
  
  long long a_sum = 0;
  for(int i=0;i<N;i++){
    a_sum += a.at(2*i+1);
  }
  
  cout << a_sum << "\n";
}