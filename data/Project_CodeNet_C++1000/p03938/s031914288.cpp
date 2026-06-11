#include<bits/stdc++.h>

using namespace std;

const int K = 1e9+1;

int main(){
  int N; cin >> N;
  
  vector<int> a(N),b(N);
  
  for(int i = 0; i < N; i++){ 
    a[i] = N*(i+1); b[i] = -N*(i+1);
  }
  
  for(int i = 0; i < N; i++){ 
    int p; cin >> p; p--;
    a[p] += i;
  }
  
  for(int i = 0; i < N; i++){ cout << a[i] << " ";}
  cout << endl;
  for(int j = 0; j < N; j++){ cout << b[j]+N*N+1 << " ";}
  
  cout << endl;
  
  return 0;
}