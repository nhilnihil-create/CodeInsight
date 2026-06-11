#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
#define MOD 1000000007
using namespace std;

int main() {
  int N; cin >> N;
  int a[N]; rep(i,0,N) cin >> a[i];
  
  for (int i =N-1; i>=0; i-=2) {
    if (i==N-1) cout << a[i];
    else cout <<" " << a[i];
  }
  for (int i = N%2; i<=N-1; i+=2) {
    cout << " " << a[i];
  }
}