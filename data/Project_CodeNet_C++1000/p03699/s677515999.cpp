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
  int N; cin >> N;
  int s[N], tot=0;
  rep(i,N) {
    cin >> s[i];
    tot += s[i];
  }
  if (tot%10!=0) cout << tot << endl;
  else {
    sort(s,s+N);
    bool found = false;
    rep(i,N) {
      if (s[i]%10!=0) {
        tot -= s[i];
        found = true;
        break;
      }
    }
    if (found) cout << tot << endl;
    else cout << 0 << endl;
  }

  // cout << fixed << setprecision(6);
  return 0;
}

