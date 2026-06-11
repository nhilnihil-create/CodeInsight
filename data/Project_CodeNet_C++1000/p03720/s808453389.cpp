#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, N, M, count=0, x;
  
  cin >> N >> M;
  
  vector<int> num(N);
  
  rep(i,2*M) {
    cin >> x;
    num[x-1] +=1;
  }
  
  rep(i,N) cout << num[i] << endl;
}

  