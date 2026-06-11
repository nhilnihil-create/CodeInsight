#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main() 
{
  ll N,M; cin>>N>>M;
  vector<string> A(N);
  vector<string> B(M);
  rep(i,N)
  {
    cin>>A.at(i);
  }
  rep(i,M)
  {
    cin>>B.at(i);
  }
  bool judge=false;
  rep(i,N-M+1)
  {
    rep(j,N-M+1)
    {
      rep(i2,M)
      {
        rep(j2,M)
        {
          if(A.at(i+i2).at(j+j2)!=B.at(i2).at(j2)) goto OUT;
        }
      }
      judge=true;
      OUT:;
    }
  }
  if(judge) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
