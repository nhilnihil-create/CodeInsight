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

int h, w, n;
int a[10000];
int ans[100][100];

int main(){
  cin >> h >> w >> n;
  rep(i, n) cin >> a[i];
  int color = 1;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(a[color-1]) ans[i][j] = color;
      else{
        ans[i][j] = color+1;
        color++;
      }
      a[color-1]--;
    }
  }
  for(int i = 1; i < h; i+=2){
    reverse(ans[i], ans[i] + w);
  }
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << ans[i][j]<<" ";
    }
    cout<<endl;
  }
  int i = 0;
}
        