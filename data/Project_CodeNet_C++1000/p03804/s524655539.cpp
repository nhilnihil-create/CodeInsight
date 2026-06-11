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
  int n, m;
  cin >> n >> m;
  string a[50], b[50];
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  for(int i = 0; i <= n - m; i++){
    for(int j = 0; j <= n - m; j++){
      bool flag = true;
      for(int k = 0; k < m; k++){
        if(b[k] != a[i+k].substr(j, m)){
          flag = false;
          break;
        }
      }
      if(flag){
        cout << "Yes" <<endl;
        return 0;
      }
    }
  }
  cout << "No"<<endl;
}