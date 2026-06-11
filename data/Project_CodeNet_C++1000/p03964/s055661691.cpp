#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int N;
ll ans;
ll a_m, t_m;

int main(){
  cin >> N;
  int t, a;
  cin >> t >> a;
  ans = t + a;
  a_m = a;
  t_m = t;
  rep(i, N - 1){
    cin >> t >> a;
    ll j = max(ans/(a+t), max(a_m / a, t_m/t));
    while(true){
      if(j *(a+t) >= ans && j*a >= a_m && j*t >= t_m){
        ans = j*(a+t);
        a_m = j * a;
        t_m = j * t;
        break;
      }
      j++;
    }
  }
  cout <<ans <<endl;
}
    