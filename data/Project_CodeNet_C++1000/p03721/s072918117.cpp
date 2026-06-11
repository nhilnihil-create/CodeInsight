#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,K,j=0; cin>>N>>K;
  vector<pair<int64_t,int64_t>> S(N);
  rep(i,N){
    int64_t a,b; cin>>a>>b;
    S.at(i)=make_pair(a,b);
  }
  sort(S.begin(),S.end());
  while(true){
    K-=S.at(j).second;
    if(K<=0){
      cout<<S.at(j).first;
      break;
    }
    j++;
  }
}