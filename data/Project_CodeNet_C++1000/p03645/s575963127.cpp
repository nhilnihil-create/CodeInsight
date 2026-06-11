#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> start(n+1);
  vector<int> end(n+1);
  for(int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    if(a == 1){
      start.at(b) = 1;
    }
    if(b == n){
      end.at(a) = 1;
    }
  }
  for(int i = 0; i < n+1; i++){
    if(start.at(i) == 1 && end.at(i) == 1){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}