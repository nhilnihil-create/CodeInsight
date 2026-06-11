#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];

  stable_sort(A.begin(), A.end(), greater<ll>());

  ll h = 0, w = 0;

  rep(i, N - 1){
    if(A[i] == A[i + 1]){
      if(h == 0){
	h = A[i];
	i++;
      } else{
	w = A[i];
	break;
      }
    }
  }

  cout << h * w << endl;
  
  return 0;
}
