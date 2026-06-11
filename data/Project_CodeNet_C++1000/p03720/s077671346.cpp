#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int N,M; cin>>N>>M;
  vector<int> S(N,0);
  rep(i,M){
    int a,b; cin>>a>>b;
    S.at(a-1)++;
    S.at(b-1)++;
  }
  rep(i,N){
    cout<<S.at(i)<<endl;
  }
}
