#include "bits/stdc++.h"
using namespace std;

int main() {
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F ;
  set<int> water, sugar;
  for(int i=0;i<=35;i++){
    for(int j=0;j<=35;j++){
      int tmp = 100*(A*i + B*j);
      if(tmp <= F){
        water.insert(tmp);
      }
    }
  }
  for(int i=0;i<=F;i++){
    for(int j=0;j<=F;j++){
      int tmp = C*i + D*j;
      if(tmp <= F){
        sugar.insert(tmp);
      }
    }
  }
  double max_cct = E/(double)(E+100);
  double cct = -1;
  int res1,res2;
  for(int w : water){
    for(int s : sugar){
      double sum = s+w;
      if(sum != 0 && s/sum <= max_cct && sum <= F && s/sum > cct){
        cct = s/sum;
        res1 = sum;
        res2 = s;
      }
    }
  }
  cout << res1 << " " << res2 << endl;
  return 0;
}