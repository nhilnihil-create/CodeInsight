#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  ll N; cin >> N;
  ll A[N];
  rep(i, N) cin >> A[i];
  ll ans = 1;
  ll wa = 0;
  sort(A, A+N);
  rep(i, N-1){
    wa += A[i];
    if (A[i+1] <= 2*wa) ans++;
    else ans = 1;
  }
  cout << ans << endl;
}
 