#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int N,M; cin >> N >> M;
  map<int,int> m;
  for(int i = 0; i < M; i++){
    int tmp1,tmp2; cin >> tmp1 >> tmp2;
    m[tmp1]++;
    m[tmp2]++;
  }

  for(auto x: m){
    if(x.second % 2 == 1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
