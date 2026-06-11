#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,a,b) for(int i=a ; i<b ; i++)
const int max_n = 1e5;
const ll mod = 1e9+7;
void send(int a,int b,int c,int d){
  printf("%d %d %d %d\n",a,b,c,d);
}
int main(){
  int h,w;  cin >> h >> w;
  int n;  cin >> n;

  vector<int> a(n);
  int ans[h][w];
  rep(i,0,n){
    int x;  cin >> a[i];
  }
  int cu = 0;
  rep(i,0,h)rep(j,0,w){
    ans[i][j] = cu + 1;
    a[cu]--;
    if(!a[cu]) cu++;
  }
  rep(i,0,h){
    rep(j,0,w){
      int x = ans[i][j];
      if(i%2 == 1){
        x = ans[i][w-1-j];
      }
      cout << x << " ";
      }
    cout << endl;
    }
    return 0;
  }
