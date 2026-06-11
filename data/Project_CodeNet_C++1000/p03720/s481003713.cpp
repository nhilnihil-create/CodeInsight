#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  
  int N, M;
  cin >> N >> M;
  vector<int> vec1(M), vec2(M);
  rep(i, M){
  cin >> vec1.at(i) >> vec2.at(i);
  }
  vector<int> vecsum(N);
  rep(i, N){
  vecsum.at(i) = 0;
  }
  rep(i, N){
  	rep(k, M){
      if(vec1.at(k) == i + 1 || vec2.at(k) == i + 1){
  		vecsum.at(i) += 1;
  	  }
    }
  }
  rep(i, N){
  cout << vecsum.at(i) << endl;
  }
}