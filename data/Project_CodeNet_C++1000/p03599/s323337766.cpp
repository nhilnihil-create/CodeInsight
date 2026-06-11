#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E>> F;
  vector<int> water;
  vector<int> sugar;
  for(int i=0; i<=F/(100*A); i++){
    for(int j=0; j<=F/(100*B); j++){
      int W = 100*A*i + 100*B*j;
      if(W<=F) water.push_back(W);
    }
  }
  sort(water.begin(), water.end());
  for(int i=0; i<=F/C; i++){
    for(int j=0; j<=F/D; j++){
      int S = C*i + D*j;
      if(S<=F) sugar.push_back(S);
    }
  }
  sort(sugar.begin(), sugar.end());
  int MAXW = 100*A;
  int MAXS = 0;
  double div = 0;
  for(int i=1; i<water.size(); i++){
    for(int j=0; j<sugar.size(); j++){
      if(water.at(i)+sugar.at(j)>F) continue;
      if(water.at(i)*E<sugar.at(j)*100) continue;
      if((double)100*sugar.at(j)/((double)water.at(i)+(double)sugar.at(j))>div){
        MAXW = water.at(i)+sugar.at(j);
        MAXS = sugar.at(j);
        div = (double)100*sugar.at(j)/((double)water.at(i)+(double)sugar.at(j));
      }
    }
  }
  cout << MAXW << ' ' << MAXS << endl;
}