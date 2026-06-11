#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;


int main(){
  int n,W;
  cin >> n >> W;
  vector<int> w(n);
  vector<int> v(n);
  vector<int> w4[4];
  rep(i, n){
    cin >> w[i] >> v[i];
    w4[w[i]-w[0]].push_back(v[i]);
  }
  rep(i, 4){
    sort(w4[i].begin(), w4[i].end(), greater<int>());
  }
  int sz1=w4[0].size();
  int sz2=w4[1].size();
  int sz3=w4[2].size();
  int sz4=w4[3].size();
  rep(i, sz1-1){
    w4[0][i+1]+=w4[0][i];
  }
  rep(i, sz2-1){
    w4[1][i+1]+=w4[1][i];
  }
  rep(i, sz3-1){
    w4[2][i+1]+=w4[2][i];
  }
  rep(i, sz4-1){
    w4[3][i+1]+=w4[3][i];
  }
  ll ans=0;
  rep(i, sz1+1){
    rep(j, sz2+1){
      rep(k, sz3+1){
        rep(l, sz4+1){
          ll wnum=0, vnum=0;
          wnum+=(ll)i*w[0];
          if(wnum>W)continue;
          wnum+=(ll)j*(w[0]+1);
          if(wnum>W)continue;
          wnum+=(ll)k*(w[0]+2);
          if(wnum>W)continue;
          wnum+=(ll)l*(w[0]+3);
          if(wnum>W)continue;
          if(i!=0){
            vnum+=w4[0][i-1];
          }
          if(j!=0){
            vnum+=w4[1][j-1];
          }
          if(k!=0){
            vnum+=w4[2][k-1];
          }
          if(l!=0){
            vnum+=w4[3][l-1];
          }
          ans=max(ans, vnum);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
