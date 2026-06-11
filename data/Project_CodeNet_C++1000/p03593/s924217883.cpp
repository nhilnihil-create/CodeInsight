#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793


int main(){
  int H, W; cin >> H >> W;
  string S[H];
  rep(i, H){
    cin >> S[i];
  }
  int cnt[30] = {};
  rep(i, H){
    rep(j, W){
      cnt[S[i][j]-'a']++;
    }
  }
  sort(cnt, cnt+30, greater<>());
  int ichi = 0, ni = 0, yon = 0;
  int ichiichi = ((H%2) && (W%2));
  int nini = ((H%2)*(W/2) + (W%2)*(H/2))*2;
  int yonyon = H*W - ichiichi - nini;
  rep(i, 30){
    if(cnt[i]%2) ichi++;
    else if(cnt[i]%4==2) ni+=2;
  }
  //cout << ichiichi << " " << nini <<" " << ichi << " " << ni <<  endl;
  if(ichi>ichiichi || ni>nini){
    cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl;  
}