#include <bits/stdc++.h>

typedef long long LL;

#define INF 1000000000
#define INF_LL_YJ 1145141919810364364

using namespace std;

#define MAX_N 100005
int N;
LL A[MAX_N];

void input()
{
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

void calcGCD()
{
  if(N == 1){
    return;
  }
  LL tmpGCD = __gcd(A[0], A[1]);
  for (int i = 2; i < N; i++) {
    tmpGCD = __gcd(tmpGCD, A[i]);
  }
  for (int i = 0; i < N; i++) {
    A[i] /= tmpGCD;
  }
}

bool solve(int turn = 0)
{
  int GuCnt = 0;
  int index = 0;

  for (int i = 0; i < N; i++) {
    if(A[i] % 2 == 0){
      GuCnt++;
    }
    else{
      index = i;
    }
  }

  if(GuCnt % 2 == 1){
    return turn == 0;
  }
  else{
    if(N-GuCnt >= 2){
      return turn != 0;
    }
    else if(N-GuCnt == 1){
      if(A[index] == 1){
        return turn != 0;
      }
      A[index]--;
      calcGCD();
      int nextTurn = turn+1;
      nextTurn %= 2;
      return solve(nextTurn);
    }
  }

}

int main()
{
  input();

  if(solve()){
    cout << "First" << endl;
  }
  else{
    cout << "Second" << endl;
  }

  return 0;
}
