#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll N;
  cin>>N;
  vector<ll> v(N);
  for(ll i = 0LL; i < N; i++) {
    int x;
    cin>>x;
    v[i]=x-1;
  }
  vector<ll> A(N),B(N);
  for(ll i = 0LL; i < N; i++){
    A[i]=1LL+(N+1LL)*i;
    B[N-1LL-i]=1LL+(N+1LL)*i;
  }
  for(ll i = 0LL; i < N; i++){
    A[v[i]]+=i;
  }
  for(ll i = 0LL; i < N; i++){
    cout<<A[i]<<" ";
  }
  cout<<endl;
  for(ll i = 0LL; i < N; i++){
    cout<<B[i]<<" ";
  }
  cout<<endl;
}