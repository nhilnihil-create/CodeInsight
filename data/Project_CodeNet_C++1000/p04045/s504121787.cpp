#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  int n, k;
  cin >> k >> n;
  bool d[10];
  fill(d, d+10, false);
  rep(i, n){
    int tmp;
    cin >> tmp;
    d[tmp] = true;
  }
  for(int i = k; 1 ; i++){
    int tmp = i;
    bool flag = true;
    while(tmp){
      if(d[tmp%10]){
        flag = false;
        break;
      }
      tmp /= 10;
    }
    if(flag){
      cout << i <<endl;
      return 0;
    }
  }
      
}