#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


int main() {
  string s;
  cin>>s;
  int sz=s.size();
  int idxa=200010,idxz=0;
  rep(i,sz){
    if(s[i]=='A'){
      idxa=min(i,idxa);
    }
    if(s[i]=='Z'){
      idxz=i;
    }
  }

  int ans=idxz-idxa+1;
  cout<<ans<<"\n";
  

  return 0;
}
