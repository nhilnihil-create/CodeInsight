#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<int> A(N+1);
  for(int i(1);i<=N;i++){
    cin>>A[i];
  }
  vector<bool> used(N+1,0);
  int cnt(0);
  for(int i(1);i<=N;i++){
    if(used[i] == false){
      if(A[A[i]] == i){
        cnt++;
        used[i] = true;
        used[A[i]] = true;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
