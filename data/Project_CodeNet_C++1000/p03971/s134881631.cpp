#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  int N,A,B; cin >>N >>A >>B;
  string S; cin >>S;
  int a=1;
  int b=1;
  rep(i,0,N) {
    if (S[i]=='a') {
      if (a<=A+B) {
        cout <<"Yes" <<endl;
        a++;
      } else {
        cout <<"No" <<endl;
      }
    } else if (S[i]=='b') {
      if (a<=A+B && b<=B) {
        cout <<"Yes" <<endl;
        a++;
        b++;
      } else {
        cout <<"No" <<endl;
      }
    } else {
      cout <<"No" <<endl;
    }
  }
  return 0;
}
