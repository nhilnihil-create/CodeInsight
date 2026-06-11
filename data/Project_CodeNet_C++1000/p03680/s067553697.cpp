#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> box(n);
  for(int i = 0; i < n; i++){
    cin >> box.at(i);
  }
  int cnt = 0, j = 0;
  for(int i = 0; i < n; i++){
    cnt++;
    if(box.at(j) == 2){
      break;
    }
    if(cnt == n){
      cout << -1 << endl;
      return 0;
    }
    j = box.at(j)-1;
  }
  cout << cnt << endl;
}