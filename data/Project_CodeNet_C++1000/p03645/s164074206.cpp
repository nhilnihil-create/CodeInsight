#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
  int N, M, a, b;
  cin >> N >> M;
  vector<set<int>> v(N + 1);
  for (int i = 0; i != M; ++i) {
    cin >> a >> b;
    v[a].insert(b);
    v[b].insert(a);
  }
 
  cout << (any_of(begin(v[1]), end(v[1]), [&](int s) { return v[s].count(N); })
               ? "POSSIBLE"
               : "IMPOSSIBLE")
       << endl;
}