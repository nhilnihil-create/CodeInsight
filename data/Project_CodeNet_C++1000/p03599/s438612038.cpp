#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int a, b, c, d, e, f;
int sugar = 0;
double res = 0;
P ans;
int main(){
  cin >> a >> b >> c >> d >> e >> f;
  
  rep(i, 31){
    rep(j, 16){
      if((a*i+b*j)*100> f) break;
      for(int k = 0;k <= 3000; k++){
        for(int l = 0; l<=1500; l++){
          sugar = k*c + l*d;
          if(sugar > (a*i+b*j)*e) break;
          double p = sugar, q = (a*i+b*j);
          if(sugar <= (a*i+b*j)*e && 100*p/(100*q+p) > res && (a*i+b*j)*100+sugar <= f){
            ans = P((a*i+b*j)*100+sugar, sugar);
            res = 100*p/(100*q+p);
          }
        }
      }
    }
  }
  if(res==0){
    cout << a*100 << " " << 0 <<endl;
    return 0;
  }
  cout << ans.first <<" " << ans.second <<endl;
}