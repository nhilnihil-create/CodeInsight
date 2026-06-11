#include <bits/stdc++.h>
using namespace std;
static const int INF = (1<<30)-1;

int main(){
  int N,T;
  cin >> N >> T;

  vector<int> town(N);
  for(int i=0;i<N;i++) cin >> town[i];

  int min_price = town[0], max_benefit = -INF, cost = 0;
  for(int i=1;i<N;i++){
    if(town[i]-min_price>max_benefit){
      max_benefit = town[i]-min_price;
      cost = 1;
    }else if(town[i]-min_price==max_benefit) cost ++;
    
    if(town[i] < min_price) min_price = town[i];
  }
  cout << cost << endl;
  return 0;
}
