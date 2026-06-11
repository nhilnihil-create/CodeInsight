#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int64_t MOD=1000000007;
const long long INF = 1LL<<60;

int main() {
  int64_t N,ans=0; cin>>N;
  vector<int64_t> S(N);
  rep(i,N) cin>>S.at(i);
  rep(i,N){
    ans+=S.at(i)/2;
    S.at(i)%=2;
    if(i<N-1&&S.at(i)==1&&S.at(i+1)!=0){
      ans++;
      S.at(i+1)--;
    }
  }
  cout<<ans<<endl;
}
