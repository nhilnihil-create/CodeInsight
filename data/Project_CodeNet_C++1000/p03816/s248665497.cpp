#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  int n;
  cin >> n;
  int ans = n;
  int a[100000];
  int cnt = 0;
  fill(a, a+100000, 0);
  for(int i = 0; i < n; i++){
    int tmp;
    cin >> tmp;
    a[tmp-1]++;
  }

  for(int i = 0; i < 100000; i++){
    if(a[i] <= 1) continue;
    if(a[i] % 2 == 0){
      cnt++;
      ans -= a[i]-2;
    }else{
      ans -= a[i]-1;
    }
  }
  if(cnt%2 == 0) ans -= cnt;
  else ans -= cnt+1;
  cout << ans <<endl;
}
      