#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;


int main() {
  int h,w;
  cin >> h >> w;
  rep(i,h){
    rep(j,w){
      string s;
      cin >> s;
      if (s=="snuke"){
        char t='A'+j;
        string g=to_string(i+1);
        cout << t << g << endl;
      }
    }
  }
}
