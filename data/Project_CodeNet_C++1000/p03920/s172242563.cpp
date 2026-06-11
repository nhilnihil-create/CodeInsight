#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin>>N;
  vector<ll>sum(N+1);
  sum[0]=0;
  for(int i=0;i<N;i++)sum[i+1]+=sum[i]+i+1;
  vector<int>ans;
  for(int i=1;i<=N;i++){
    if(sum[i]>=N){
      int memo=sum[i]-N;
      for(int j=1;j<=i;j++){
        if(j==memo)continue;
        cout<<j<<endl;
      }
      return 0;
    }
  }
  return 0;
}
