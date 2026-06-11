#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N, M; cin >> N >> M;
  string s[N], t[M];
  rep(i,N) cin >> s[i];
  rep(i,M) cin >> t[i];

  if (M>N) {
    cout << "No" << endl;
    return 0;
  }

  bool ans = false;
  rep(row,N-M+1){
    rep(col,N-M+1){
      // cout << row << " " << col << endl;
      bool check = true;
      for (int i=0;i<M;i++){
        if (s[row+i].substr(col,M)!=t[i]) check = false;
      }
      if (check) ans = true;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;

  // cout << fixed << setprecision(10);
  
  return 0;
}
