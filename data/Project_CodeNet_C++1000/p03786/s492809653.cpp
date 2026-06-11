#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin>>N;
  vector<ll> S(N);
  vector<ll> v(N);
  for(int i = 0; i < N;i++)cin>>v[i];
  sort(v.begin(),v.end());
  for(int i = 0; i < N; i++){
    if(i==0)S[i]=v[i];
    else S[i]=S[i-1]+v[i];
  }
  int ans=1;
  for(int i = N-1;i>=1;i--){
    if(S[i]<=3*S[i-1]) ans++;
    else break;
  }
  cout<<ans<<endl;
}