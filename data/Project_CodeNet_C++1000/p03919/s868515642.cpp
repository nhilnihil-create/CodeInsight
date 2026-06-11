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

  int H,W;
  cin>>H>>W;
  string snuke="snuke";
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      string S;
      cin>>S;
      if(S==snuke){
        cout<<(char)('A'+j)<<i+1<<endl;
      }
    }
  }
  return 0;
}
