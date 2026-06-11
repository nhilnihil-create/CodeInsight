#include <bits/stdc++.h>
using namespace std;

int64_t binomial(int64_t N, int64_t K) {
  if(K < 0 || N < K) return 0;
  int64_t ret = 1;
  for(int64_t i = 1; i <= K; ++i) {
    ret *= N--;
    ret /= i;
  }
  return ret;
}

int main(){

  int N,A,B;
  cin>>N>>A>>B;
  vector<int64_t> v(N);
  for(int i=0;i<N;++i) cin>>v[i];

  sort(v.begin(),v.end(),greater<int64_t>());
  double av=0;
  for(int i=0;i<A;++i) av += v[i];
  av /= A;

  cout<<fixed<<setprecision(10);
  cout<<av<<endl;

  int n=0,m=0;
  for(int i=0;i<N;++i){
    if(v[i]==v[A-1]){
      ++n;
    if(i<A) ++m;
    }
  }
  int64_t ans=0;
  ans += binomial(n,m);
  if(m==A){
    for(int i=A+1;i<=B;++i) ans += binomial(n,i);
  }
  
  cout<<ans<<endl;
}
