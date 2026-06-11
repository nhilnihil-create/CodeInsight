#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

int write_move(char c, int dist) {
  REP(i, dist) {
    cout << c;
  }
}

int sign(int x) {
  return (x>0)-(x<0);
}

int main(){
  int N, M;
  cin >> N >> M;
  int dist[100][100];
  REP(i, N) {
    REP(j, N) {
      dist[i][j] = i == j ? 0 : 999999;
    }
  }
  vector<tuple<int,int,int>> v;
  REP(i, M) {
    int A, B, C;
    cin >> A >> B >> C;
    A--; B--;
    dist[A][B] = C;
    dist[B][A] = C;
    v.push_back(make_tuple(A, B, C));
  }
  REP(k, N) {
    REP(i, N) {
      REP(j, N) {
        int ndist = dist[k][i] + dist[k][j];
        if(dist[i][j] > ndist) {
          dist[i][j] = ndist;
          dist[j][i] = ndist;
        }
      }
    }
  }
  int ret = 0;
  for(auto itr = v.begin(); itr != v.end(); ++itr) {
    int A = get<0>(*itr), B = get<1>(*itr), C = get<2>(*itr);
    if(dist[A][B] < C) {
      ++ret;
    }
  }
  cout << ret << endl;
}