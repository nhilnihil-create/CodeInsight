#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Nbit= 1e5;
  int N,M;
  cin >> N >> M;

  bitset<Nbit> filter;
  for(int i=0; i<N; i++){
    filter.set(i);
  }
  
  vector<int> data(N, 1);
  bitset<Nbit> plausible;
  plausible.set(0);
  int from,to;
  for(int j=0; j<M; j++){
    cin >> from >> to;
    from--; to--; // 1-indexed -> 0-indexed
    data.at(from)--;
    data.at(to)++;
    if(plausible.test(from)){
      plausible.set(to);
    }
    if(data.at(from)==0){
      plausible.reset(from);
    }
  }

  int ans= (plausible & filter).count();

  cout << ans << endl;
}