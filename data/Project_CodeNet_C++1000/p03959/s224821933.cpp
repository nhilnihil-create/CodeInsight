#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){
  int N;
  cin >> N;
  
  vector<long long> T(N), A(N);
  
  for(int i = 0; i < N; i++){
    cin >> T[i];
  }
  
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  
  vector<long long> l(N, 0), r(N, 0);
  l[0] = T[0], r[N - 1] = A[N - 1];
  
  for(int i = 1; i < N; i++){
    if(T[i - 1] < T[i]) l[i] = T[i];
  }
  
  for(int i = N - 2; i >= 0; i--){
    if(A[i] > A[i + 1]) r[i] = A[i];
  }
  
  long long p = 1;
  for(int i = 0; i < N; i++){
    if(l[i] && l[i] > A[i]) p = 0;
    else if(r[i] && r[i] > T[i]) p = 0;
    else if(!l[i] && !r[i]) p *= min(T[i], A[i]);
    p %= mod;
  }
  
  if(p < 0) p += mod;
  cout << p << endl;
  
  return 0;
}