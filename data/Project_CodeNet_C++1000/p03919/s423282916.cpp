#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main() {
    int h , w ; cin >> h >> w ;
  rep(i,h){
    rep(j,w){
      string s; cin>>s;
      if(s=="snuke"){
        cout<<(char)('A'+j)<<i+1<<endl;
        break;
      }
    }
  }
}

