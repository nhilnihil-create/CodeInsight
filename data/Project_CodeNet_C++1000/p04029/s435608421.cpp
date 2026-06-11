#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  int N; cin >>N;
  int ans=0;
  rep_eq(i,1,N) {
    ans+=i;
  }
  cout <<ans <<endl;
  return 0;
}
