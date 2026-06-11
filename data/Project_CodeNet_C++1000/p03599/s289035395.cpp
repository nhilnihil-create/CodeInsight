#include <bits/stdc++.h>
using namespace std;

bool sugar(int x,int y,int z){
  int i=0;
  while(x*i<=z){
    if((z-x*i)%y==0) return true;
    i++;
  }
  return false;
}

int main() {
  int A,B,C,D,E,F;
  cin >> A >> B >> C >> D >> E >> F;
  int best_noudo=0;
  int best_whole=0;
  int best_sugar=0;
  vector<int>water;
  for(int i=0;i<31;i++){
    for(int j=0;j<31;j++){
      int x=A*i+B*j;
      if(x*100<=F&&x!=0) water.push_back(x);
    }
  }
  
  int w=water.size();
  for(int i=0;i<w;i++){
    int x=water.at(i);
    int j=min(x*E,F-100*x);
    double data=0;
    while(true){
      if(sugar(C,D,j)){
        data=j;
        break;
      }
      j--;
    }
    if(best_whole*data>=best_sugar*(100*x+data)){
      best_whole=100*x+data;
      best_sugar=data;
      best_noudo=data/x;
    }
  }
  cout << best_whole << " " << best_sugar << endl;
}