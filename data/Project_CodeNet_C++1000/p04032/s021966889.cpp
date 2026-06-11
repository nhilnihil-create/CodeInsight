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
using vpii = vector<pll>;

int main(){
  string s;
  cin >> s;
  ll N = s.size();

  ll left = -1, right = -1;

  rep(i, N){
    if(i < N -1){
      if(s[i] == s[i+1]){
		left = i + 1;
		right = i + 2;
		break;
      }
    }

    if(i < N - 2){
      if(s[i] == s[i + 2]){
        left = i + 1;
        right = i + 3;
        break;
      }
    }
  }

  cout << left << ' ' << right << endl;
  
  return 0;
}
