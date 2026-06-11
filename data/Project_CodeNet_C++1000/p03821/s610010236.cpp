#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int n;
vector<llint>A,B;
void solve(){
  cin >> n;
  A.resize(n);
  B.resize(n);
  for(int i=n-1;i>=0;i--){
      cin >> A[i] >> B[i];
  }
  llint ans=0;
  for(int i=0;i<n;i++){
      if((A[i]+ans)%B[i]==0)continue;
      llint x=B[i]-((A[i]+ans)%B[i]);
      ans+=x;
  }
  cout << ans << endl;

}

int main(){
  solve();
  return 0;
}
