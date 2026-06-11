#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589;

int a[100000];
bool flag = true;
ll n, p;
ll ans = 0;
int main(){
  int N;
  cin >> N;
  if(N % 2 == 0){
    int tmp;
    rep(i, N){
      cin >> tmp;
      if(tmp %2 == 0){
        flag = false;
        break;
      }
      tmp /= 2;
      a[tmp]++;
      if(a[tmp] > 2){
        flag = false;
        break;
      }
    }
    if(flag){
      ans = 1;
      n = N/2;
      p = 2;
      while(n > 0){
        if(n & 1) ans = ans * p % MOD;
        p = p * p % MOD;
        n >>= 1;
        //cout << ans <<endl;
      }
    } 
  }else{
    int tmp;
    rep(i, N){
      cin >> tmp;
      if(tmp %2 == 1){
        flag = false;
        break;
      }
      tmp /= 2;
      a[tmp]++;
      if(a[0] > 1){
        flag = false;
        break;
      }else if(a[tmp] > 2){
        flag = false;
        break;
      }
    }
    if(flag){
      ans++;
      n = N/2;
      p = 2;
      while(n > 0){
        if(n & 1) ans = ans * p % MOD;
        p = p * p % MOD;
        n >>= 1;
        //cout << ans <<endl;
      }
    }
  }
  cout << ans <<endl;
}