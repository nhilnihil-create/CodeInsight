#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repeat(i,s,n) for(int (i)=s; (i)<(n); (i)++)
#define revrep(i,n) for(int (i)=(n)-1;i>=0; i--)

string solve(ll x, ll y) {

}

// true is alice
// false is brown
bool simulate(ll x, ll y) {
  // x<=y
  if(x<=1&&y<=1) {
    return false;
  }
  for(ll i=1; 2*i<=x; i++) {
    if(!simulate(x-2*i,y+i)) {
      return true;
    }
  }
  for(ll i=1; 2*i<=y; i++) {
    if(!simulate(x+i,y-2*i))
      return true;
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<setprecision(std::numeric_limits<float>::max_digits10);
  // rep(x,10) {
  //   rep(y,10) {
  //     cout << "x="<<x<<",y="<<y;
  //     if(simulate(x,y)) {
  //       cout << ",winner=Alice" << endl;
  //     } else {
  //       cout << ",winner=Brown"<<endl;
  //     }
  //   }
  // }
  ll x,y;
  cin>>x>>y;
  if(abs(x-y)<=1) {
    cout << "Brown" << endl;
  } else {
    cout << "Alice" << endl;
  }
  return 0;
}
