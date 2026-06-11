#include<iostream>
using namespace std;

bool s[100010], dp[100010];

bool satisfies(int N) {
  for (int i = 2; i < N; i++) {
    dp[i] = dp[i-1] ^ dp[i-2] ^ s[i-1];
  }
  return (dp[N-1] ^ dp[N-2] ^ s[N-1] == dp[0] && dp[0] ^ dp[N-1] ^ s[0] == dp[1]);
}

void print_dp(int N) {
  for (int i =0; i < N; i++) {
    cout<<(dp[i] ? 'W' : 'S');
  }
  cout<<endl;
}

int main() {
  int N; cin>>N;
  string S; cin>>S;
  for (int i = 0; i < N; i++) s[i] = (S[i] == 'x');
  dp[0]=dp[1]=0;
  if (satisfies(N)) { print_dp(N); return 0;}
  dp[1] = 1;
  if (satisfies(N)) { print_dp(N); return 0;}
  dp[0] = 1;
  if (satisfies(N)) { print_dp(N); return 0;}
  dp[1] = 0;
  if (satisfies(N)) { print_dp(N); return 0;}
  cout<<-1<<endl;
}