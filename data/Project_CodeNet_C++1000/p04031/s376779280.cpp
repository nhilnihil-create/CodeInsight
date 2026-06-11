#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, cost, costex;
  cin >> N;
  costex = 0;
  cost = 200*200*N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  for (int AVE = -100; AVE < 101; AVE++){
    costex=0;
    for (int i=0; i<N; i++){
      costex+=(a.at(i)-AVE)*(a.at(i)-AVE);
    }
    if (costex < cost){
      cost = costex;
    }
  }
  cout << cost <<endl;
}