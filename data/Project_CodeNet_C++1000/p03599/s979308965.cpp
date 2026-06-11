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

ll A, B, C, D, E, F;

int main(){
  cin >> A >> B >> C >> D >> E >> F;
  pll rat = {0, 1};
  ll tot = 0, sugar = 0;

  rep(n1, 31){
    rep(n2, 31){      
      rep(n3, 101){
	rep(n4, 101){
	  ll t = 100*(n1*A + n2*B) + (n3*C + n4*D);
	  ll s = n3*C + n4*D;

	  if((t <= F) && (100*s <= (t-s)*E) && (s*rat.second > t*rat.first)){
	    rat.first = s;
	    rat.second = t;
	    tot = t;
	    sugar = s;
	  }
	}
      }
    }
  }

  if((tot == 0) && (sugar == 0))
    cout << 100*A << ' ' << 0 << endl;
  else
    cout << tot << ' ' << sugar << endl;

  return 0;
}
