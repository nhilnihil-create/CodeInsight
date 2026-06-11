#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[100010];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
  long long n, k;
  cin >> n >> k;
  long long a[n];
  rep(i,n)
    cin >> a[i];
  long long ans = INF;
  rep(i,(1<<n)){
    if(bitset<64>(i).count()==k){
      int bit[30];
      rep(j,n)
        bit[j] = (i/(1<<j))%2;
      bool flag = true;
      long long tmp=0, pre = 0;
      rep(j,n){
        if(bit[j]==0)
          chmax(tmp, a[j]);
        if(bit[j]==1){
          if(flag){
            chmax(tmp, a[j]);
            flag = false;
          } else{
            if(a[j]<=tmp){
              tmp++;
              pre += tmp-a[j];
            } else {
              tmp = a[j];
            }
          }
        }
      }
      chmin(ans,pre);
    }
  }
  cout << ans << endl;
}
