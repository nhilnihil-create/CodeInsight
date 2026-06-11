#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(N), c(M), d(M);
  rep(i,N){
    cin >> a.at(i) >> b.at(i);
  }
  rep(i,M){
    cin >> c.at(i) >> d.at(i);
  }
  rep(i,N){
    int dist = 1e9;
    int index;
    rep(j,M){
      int tmp = abs(a.at(i)-c.at(j))+abs(b.at(i)-d.at(j));
      if(tmp<dist){
        dist = min(dist,tmp);
        index = j+1;
      }
    }
    cout << index << endl;
  }
  return 0;
}