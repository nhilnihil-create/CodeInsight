#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
 
int main() {
  
  int N;

  cin >> N;

  vector<int> L(2*N);

  REP(i,2*N) cin >> L.at(i);//入力終了

  sort(L.begin(),L.end());

  reverse(L.begin(),L.end());

  int64_t ans=0;

  for(int i=0;i<N;i++){
    ans+=L.at(2*i+1);
  }

  cout<< ans << endl;
  
  return 0;
}