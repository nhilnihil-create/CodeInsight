#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K, X, Y;
  cin >> N;
  cin >> K;
  cin >> X;
  cin >> Y;
  int sum;
  if (N>=K){
    sum = K*X+(N-K)*Y;
  }
  else {
    sum = N*X;
  }
  cout << sum << endl;
}
