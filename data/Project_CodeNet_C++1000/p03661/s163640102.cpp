#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  
  for(long long &i: A)
    cin >> i;
  
  long long x = 0;
  long long y = accumulate(A.begin(), A.end(), 0LL);
  long long min_ = pow(10, 15);
  
  for(int i = 0; i < N - 1; i++){
    x += A.at(i);
    y -= A.at(i);
    long long dif = abs(x - y);
    if(dif < min_)
      min_ = dif;
  }
  
  cout << min_ << endl;
}
