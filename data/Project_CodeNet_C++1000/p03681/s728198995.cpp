#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

long long kaijo(long long n, long long m){
  m %= 1000000007;
  if(n == 0 || n == 1) return(m);
  else return kaijo (n - 1, m * n);
}

int main(){
  long long N, M, count;
  cin >> N >> M;
  if(N == M) count = 2 * kaijo(N, 1) * kaijo(M , 1);
  else if(N == M + 1|| M == N + 1) count = kaijo(N, 1) * kaijo(M , 1);
  else count = 0;
  count %= 1000000007; 
  cout << count << endl;
}