#include "bits/stdc++.h"
using namespace std;

int main(){
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;

  set<int> waters, sugars;
  for( int i = 0; i <= 30; i++){
    for(int j = 0; j <= 30; j++){
      //if(i == 0 && j == 0) continue;
      int x = (100 * A * i) + (100 * B * j);
      if(x <= F){
        waters.insert(x);
      }
    }
  }

  for(int i = 0; i <= F ; i++){
    for(int j = 0; j <= F ; j++){
      //if(i == 0 && j == 0) continue;
        int y = (i * C) + (j * D);
        if(y <= F){
          sugars.insert(y);
        }
    }
  }

  int max_sum = 0;
  int max_sugar = 0;
  double max_per = -1.0;
  for (int x : waters){
    for (int y : sugars){
      int sum = x + y;
      if(sum > F) continue;
      double per = 100.0 * y / sum;
      if(y <= E * x / 100){
        if(per > max_per){
          //cout << sum << " " << y << endl;
          max_sum = sum;
          max_sugar = y;
          max_per = per;
        }
      }
    }
  }

  cout << max_sum << " " << max_sugar << endl;

}