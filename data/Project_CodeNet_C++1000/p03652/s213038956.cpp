#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;

int main(){
  int N, M; cin >> N >> M;

  int A[N][M];
  for (int i = 0; i < N; i++){
    for (int j = 0; j < M; j++){
      cin >> A[i][j]; A[i][j]--;
    }
  }

  int ans = N, cnt = 0;
  vector <int> now(N);
  vector <bool> visited(M);
  while (cnt < M){
    vector < pair<int, int> > count(M);
    for (int i = 0; i < M; i++){
      count[i] = make_pair(0, i);
    }

    for (int i = 0; i < N; i++){
      int sport = A[i][now[i]];
      count[sport].first++;
    }
    sort(count.begin(), count.end(), greater<pair<int, int> >());
    
    ans = min(ans, count[0].first);
    visited[count[0].second] = true;

    for (int i = 0; i < N; i++){
      for (int j = now[i]; j < M; j++){
        int sport = A[i][j];
        if (visited[sport] == false){
          break;
        }else{
          now[i]++;
        }
      }
    }
    cnt++;
  }
  cout << ans << endl;

  return 0;
}