#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N; cin >> N;
  int K; cin >> K;

  int ans = 0;
  for(int i = 0; i < N ; i++){
    int tmp; cin >> tmp;
    ans += min(abs(tmp), abs(K - tmp));
  }
  cout << ans * 2 << endl;
}
