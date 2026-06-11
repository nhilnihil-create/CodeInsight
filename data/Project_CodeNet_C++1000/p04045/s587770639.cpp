#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N, K;
  cin >> N >> K;
  vector<int> D(10, 0);
  rep(i, K){
    int x;
    cin >> x;
    D.at(x) = 1;
  }
  
  for(int i=N; i<=999999; ++i){
    int tmp=i;
    bool flg = true;
    while(tmp !=0){
    	if(D.at(tmp%10) == 1){
          flg = false;
          break;
        }
      tmp /=10;
    }
    if(flg){
      cout << i << endl;
      break;
      
    }
  }
  return 0;
}