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

int n;
int main(){
  cin >> n;
  int ans = 0;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    ans += b - a + 1;
  }
  cout << ans <<endl;
}