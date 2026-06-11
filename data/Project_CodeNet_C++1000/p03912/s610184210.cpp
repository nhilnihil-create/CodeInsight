#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <utility>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long int ll;
const ll  MOD = 1000000007;
typedef pair<int,int> P;

int N,M;
int v[100100];
int tmp_cnt[100100];
int cnt[100100];
int ans=0;
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    int t;
    cin >> t;
    v[t%M]++;
    tmp_cnt[t]++;
    if(tmp_cnt[t] == 2){
      cnt[t%M]++;
      tmp_cnt[t] = 0;
    }
  }
  /*
  for(int i=0;i<M;i++){
    cout << v[i] << " " << cnt[i] << endl;
  }
  */
  for(int i=1;i<(M+1)/2;i++){
    int tmp = min(v[i],v[M-i]);
    ans += tmp;
    if(v[i] - tmp < cnt[i]*2){
      cnt[i] = (v[i] - tmp) / 2;
    }
    if(cnt[i] > 0) ans += cnt[i];

    if(v[M-i] - tmp < cnt[M-i]*2){
      cnt[M-i] = (v[M-i] - tmp) / 2;
    }
    if(cnt[M-i] > 0) ans += cnt[M-i];
    //cout << " "<< i << " " << ans << endl;
  }
  ans += v[0] / 2;
  if(M%2 == 0) ans += v[M/2]/2;
  cout << ans << endl;
}
