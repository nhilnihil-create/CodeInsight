#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++)
#define ll long long
using namespace std;

int main() {
  int N,M; cin >> N >> M;
  int c[N]; rep(i,0,N) c[i] =0;
  rep (i,0,M) {
    int a,b; cin >> a >> b;
    c[a-1]++; c[b-1]++;
  }
  
  rep(i,0,N) cout << c[i] << endl;
}