#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;
    vec<int> Z(N,1);
    vec<bool> R(N,false);
    R[0] = true;

    int root = 0;
    rep(i,M){
      int x,y;
      cin >> x >> y;
      --x,--y;
      if(R[x]) R[y]=true;
      --Z[x],++Z[y];
      if(Z[x]==0) R[x] = false;
       
    }
    
    int ans = 0;
    rep(i,N){
      if(R[i]) ++ans;
    }
    cout << ans << '\n';
}
