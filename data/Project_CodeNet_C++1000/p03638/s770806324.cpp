#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define ALL(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vs = vector<string>;
using vb = vector<bool>;
using vll = vector<long long>;
using vpii = vector<pair<int,int>>;
using vivi = vector<vector<int>>;
using vbvb = vector<vector<bool>>;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int mod = 1000000007;
const int inf = 1001001001;



int main(void) {
  int h,w,n;
  cin >> h >> w >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  vivi s(h,vi(w,0));
  pii last = make_pair(0,-1);
  rep(i,n){
    while(a[i]>0){
      if(!(last.first%2)){
      	rep2(j,last.second+1,w){
          if(a[i]==0) break;
          s[last.first][j] = i+1;
          a[i]--;
          if(j==w-1) {
            last.first++;
            last.second = w;
          }
          else if(a[i]==0) {
            last.second = j;
            break;
          }
      	}  
   	  }
      else{
        for(int j = last.second-1;j>=0;j--){
          if(a[i]==0)break;
          s[last.first][j] = i+1;
          a[i]--;
          if(j==0){
            last.first++;
            last.second = -1;
          }
          else if(a[i]==0){
            last.second = j;
            break;
          } 
        }
      }
    }
  }
  rep(i,h)rep(j,w){
    cout << s[i][j] << " ";
    if(j==w-1) cout << endl;
  }
}


