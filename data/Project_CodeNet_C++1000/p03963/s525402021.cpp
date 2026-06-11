#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  ll ans = 1;
  int N;
  ll K;
  cin >> N >> K;
  ans *= K;
  for(int i = 0; i < N-1; i++){
    ans *= K-1;
  }
  cout << ans << endl;
}

