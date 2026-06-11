#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
#define fix10 cout << fixed << setprecision(10);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  //vector<int> a(n);
  vvi data(h,vi(w));
  int x = 0;
  int y = 0;
  int c = 0;
  rep(i,n){
    int a;
    cin >> a;
    c++;
    rep(j,a){
      data.at(x).at(y) = c;
      if(x % 2 == 0){
        if(y == w-1){
          x++;
        }else y++;
      }else{
        if(y == 0){
          x++;
        }else y--;
      }
    }
  }
  rep(i,h){
    rep(j,w) cout << data.at(i).at(j) << " ";
    cout << endl;
  }
}
