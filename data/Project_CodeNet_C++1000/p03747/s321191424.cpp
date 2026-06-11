#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  long long N, L, T;
  cin >> N >> L >> T;
  //T %= L;
  vector<long long> X;
  int c = 0;
  for(int i = 0; i < N; ++i){
    long long x, w, x_;
    cin >> x >> w;
    if(w == 1) x_ = x+T;
    else x_ = x-T;
    c += x_/L;
    x_ %= L;
    if(x_ < 0) --c, x_ += L;
    X.push_back((L+x_%L)%L);
  }
  //cerr << c << endl;
  sort(X.begin(), X.end());
  for(int i = 0; i < N; ++i){
    cout << X[(i+N+c%N)%N] << endl;
  }
}
