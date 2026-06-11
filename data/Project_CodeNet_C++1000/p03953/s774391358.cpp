#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)
#define all(x) x.begin(),x.end()
int N;

int M;
i64 K;
vector<i64> x;
vector<i64> a;
vector<i64> d;
int main(){
  cin >> N;
  x.resize(N);
  rep(i,0,N - 1) cin >> x[i];
  cin >> M >> K;
  a.resize(M);
  rep(i,0,M - 1) cin >> a[i];
  rep(i,0,M - 1) a[i]--;
  d.resize(N - 1);
  rep(i,0,N - 2){
    d[i] = x[i + 1] - x[i];
  }
  vector<int> sw(N - 1);
  rep(i,0,N - 2) sw[i] = i;
  rep(i,0,M - 1){
    swap(sw[a[i] - 1],sw[a[i]]);
  }

  vector<int> ret(N - 1);
  rep(i,0,N - 2) ret[i] = i;

  while(K){
    if(K & 1){
      vector<int> temp(N - 1);
      rep(i,0,N - 2) temp[i] = ret[sw[i]];
      ret = temp;
    }
    {
      vector<int> temp(N - 1);
      rep(i,0,N - 2) temp[i] = sw[sw[i]];
      sw = temp;
    }
    K >>= 1;
  }

  vector<i64> ans(N);
  ans[0] = x[0];
  rep(i,1,N - 1){
    ans[i] = d[ret[i - 1]] + ans[i - 1];
  }

  rep(i,0,N - 1){
    cout << ans[i] <<endl;
  }
}
