#include <iostream>
#include <string>
#include <algorithm>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

int main() {
  int N, M, A[300][300];
  cin >> N >> M;
  REP(i, N) {
    REP(j, M) {
      int _A;
      cin >> _A;
      A[i][j] = _A - 1;
    }
  }
  bool hold[300];
  REP(i, M) {
    hold[i] = true;
  }
  
  int ret = 999;
  while(true) {
    int participant[300] = {};
    REP(i, N) {
      int tsp = -1;
      REP(j, M) {
        if(hold[A[i][j]]) {
          tsp = A[i][j];
          break;
        }
      }
      participant[tsp]++;
    };
    int maxp = *max_element(participant, participant + M);
    if(maxp < ret) {
      ret = maxp;
    }
    REP(i, M) {
      if(participant[i] == maxp) {
        hold[i] = false;
      }
    }
    int flag = false;
    REP(i, M) {
      if(hold[i]) {
        flag = true;
        break;
      }
    }
    if(!flag) {
      break;
    }
  }
  cout << ret << endl;
}