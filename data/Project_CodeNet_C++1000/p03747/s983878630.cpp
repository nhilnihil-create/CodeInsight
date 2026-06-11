#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
#define REP(i, n) for (ll i = 0; i < (int)(n); i++)
#define RREP(i, n) for (ll i = (int)(n)-1; i > -1 ; i--)
#define IN(T, x) T x;cin >> x;
#define AIN(T, a, n) vector<T> a(n);REP(i, n){cin >> a[i];}
#define A2IN(T1, a, T2, b, n) vector<T1> a(n);vector<T2> b(n);REP(i, n){cin >> a[i] >> b[i];}
#define ALL(a) (a).begin(),(a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) SORT(a);reverse(ALL(a))
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
#define OUT(x) cout << x << endl
#define BOUT(b) if(b){OUT("Yes");}else{OUT("No");}

int main() {
  IN(ll, N);
  IN(ll, L);
  IN(ll, T);
  vector<vector<ll>> X(N,vector<ll>(2,0));
  vector<ll> W(N);
  REP(i, N){
    cin >> X[i][0];
    cin >> W[i];
  }
  int count = 0;
  int ant0 = 0;
  if(W[0] == 1){
    for(int i = 1; i < N; i++){
      if(W[0] != W[i]){
        ll d = X[i][0] - X[0][0];
        count += (2*T)/L;
        if((2*T)%L >= d)
          count++;
      }
    }
    count %= N;
    ant0 = count;
  }
  else{
    for(int i = 1; i < N; i++){
      if(W[0] != W[i]){
        int d = X[i][0] - X[0][0];
        count += (2*T)/L;
        if((2*T)%L >= L-d)
          count++;
      }
    }
    count %= N;
    ant0 = (N - count)%N;
  }
  if(W[0] == 1)
    X[0][1] = 1;
  else
    X[0][1] = -1;
  REP(i, N){
    if(W[i] == 1)
      X[i][0] = (X[i][0] + T)%L;
    else
      X[i][0] = (L + X[i][0] - T%L)%L;
  }
  SORT(X);
  int num = 0;
  REP(i, N){
    if(X[i][1] != 0){
      num = i;
    }
  }
  ant0 = (N + num - ant0)%N;
  for(int i = 0; i < N; i++){
    OUT(X[(i+ant0)%N][0]);
  }
}