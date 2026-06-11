#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};


int main(){
  int H,W; cin >> H >> W;
  int n; cin >> n;
  vi a(n); rep(i, n) cin >> a[i];

  vvi c(H,vi(W,-1));

  int h = 0, w = 0;
  int col = 0;
  int cnt = 1;
  int dir = 0;
  while (col < n) {
    //printf("h:%d w:%d\n",h, w );
    c[h][w] = col+1;
    if(cnt+1 <= a[col]) cnt++;
    else{
      cnt = 1;
      col++;
    }
    int nh = h + dh[dir];
    int nw = w + dw[dir];
    if(nh < 0 || nh == H || nw < 0 || nw == W || c[nh][nw] != -1){
      dir = (dir + 1)%4;
      nh = h + dh[dir];
      nw = w + dw[dir];
    }
    h = nh;
    w = nw;
  }

  rep(h, H){
    rep(w, W){
      if(w < W-1) std::cout << c[h][w] << " ";
      else std::cout << c[h][w] << '\n';
    }
  }
}
