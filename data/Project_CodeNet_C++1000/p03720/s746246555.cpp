#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M = 0;
  cin >> N >> M;
  vector<int> count(M*2);
  
  for(int i=0;i<M*2;i++){
    cin >> count.at(i);
  }
  for(int i=1;i<=N;i++){
    int sum = 0;
    for(int j=0;j<M*2;j++){
      if(i == count.at(j)){
        sum++;
      }
    }
    cout << sum << endl;
  }
}