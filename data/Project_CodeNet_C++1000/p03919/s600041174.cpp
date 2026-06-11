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
  for(int y=0;y<H;y++){
    for(int x=0;x<W;x++){
      string s;
      cin>>s;
      if(s=="snuke"){
        cout<<(char)(x+'A')<<y+1<<endl;
        return 0;
      }
    }
  }
  return 0;
}
