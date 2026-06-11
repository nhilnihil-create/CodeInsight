#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  int N,M;
  cin>>N>>M;
  int cnt[100001] = {0};
  for(int i(0);i<M;i++){
    int a,b;
    cin>>a>>b;
    cnt[a]++;
    cnt[b]++;
  }
  for(int i(1);i<=N;i++){
    if(cnt[i]%2){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
