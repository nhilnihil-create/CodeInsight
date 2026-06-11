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
const int MAX_C = 1000;
long long Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]);
        }
    }
}


int main(){
  int N, a, b; cin >> N >> a >> b;
  ll v[N];
  rep(i, N){
    cin >> v[i];
  }
  sort(v, v+N, greater<ll>()); ll sum = 0;
  rep(i, a){
    sum += v[i];
  }
  double h = (double)sum/a; printf("%.12lf\n", h); int dai;
  rep(i, N){
    if(v[i]==v[a-1]){dai = i; break;}
  }
  int cnt = 0, low=-1;
  rep(i, N){
    if(v[i]==v[a-1]) cnt++;
    if(v[i]<v[a-1]){low=i; break;} 
  }
  if(low==-1) low=N;
  //cout << cnt << endl;
  calc_com();
  if(v[0]!=v[a-1]){
    a-=dai; a=min(a, cnt);
    cout << Com[cnt][a] << endl; return 0;
  }
  ll ans = 0; b = min(b, low);
  //cout << a << " " << b << endl;
  for(int i=a; i<=b; i++){
    ll tmp = Com[cnt][i];
    ans+=tmp; 
  }
  cout << ans << endl;
}