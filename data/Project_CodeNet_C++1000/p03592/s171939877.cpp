#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

int main(){
  int N,M,K;
  cin>>N>>M>>K;
  for(int i(0);i<=N;i++){
    for(int j(0);j<=M;j++){
      int k = i*j+(N-i)*(M-j);
      if(k == K){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
