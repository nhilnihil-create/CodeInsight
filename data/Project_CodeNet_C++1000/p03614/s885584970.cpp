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
  vector<int>p(N);
  for(int i=0;i<N;i++)cin>>p[i];
  bool ok=false;
  int ans=0;
  for(int i=0;i<N;i++){
    if(i==N-1&&p[i]==i+1){
      ans++;
    }
    else if(ok&&p[i]==i+1){
      ok=false;
      ans++;
    }
    else if(ok){
      ok=false;
      ans++;
    }
    else if(!ok&&p[i]==i+1){
      ok=true;
    }
  }
  cout<<ans<<endl;
  return 0;
}
