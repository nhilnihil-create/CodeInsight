#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,dr,ti,ans;
  cin >> N;
  vector<int>ques(N);
  for (int i=0; i<N; i++){
    cin >> ques.at(i);
  }
  cin >> M;
  for (int i=0; i<M; i++){
    cin >> dr >> ti;
    dr--;
    ans = 0;
    for (int j=0; j<N; j++){
      if (j==dr){
        ans += ti;
      }else{
        ans += ques.at(j);
      }
    }
    cout << ans << endl;
  }
}