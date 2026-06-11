#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  int count;
  bool owata=false;
  for(int i=0;i<S.size()-1;i++){
    if(S.at(i)==S.at(i+1)){
      cout << i+1 << " " << i+2 << endl;
      owata=true;
      break;
    }
  }
  if(!owata)
  for(int j=0;j<S.size()-2;j++){
    if(S.at(j)==S.at(j+2)){
      cout << j+1 << " " << j+3 << endl;
      owata=true;
      break;
    }
  }
  if(!owata)
    cout << -1<<" "<<-1<<endl;
}

