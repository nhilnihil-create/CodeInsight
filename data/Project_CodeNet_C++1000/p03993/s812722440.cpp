#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<int> v(N);
  map<int,int> flg;
  for(int i = 0; i < N; i++){
    cin >> v[i];
    v[i]--;
  }

  int ans = 0 ;
  for(int i = 0; i < N; i++){
    flg[i] = 1;
    if(flg.count(v[i]) == 0){
      if(v[v[i]] == i){
        ans++;
        flg[v[i]]++;
      }
    }
  }
  cout << ans << endl;
}
