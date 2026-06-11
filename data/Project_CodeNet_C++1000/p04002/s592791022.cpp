#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
#define ld long double
int inf=100000000;
ll INF=4000000000000000000;
ll MOD=1000000007;



int main() {
   ll h,w;
   int n;
   cin >> h >> w >> n;
  set<pair<ll,ll>> s;
  vector<ll> a(10);
  rep(i,10) a.at(i)=0;
  a.at(0)=(h-2)*(w-2);
  ll x,y;
  rep(i,n){
    cin >> y >> x;
    s.insert(make_pair(x,y));
    vector<vector<int>> b(5,vector<int>(5));
    rep(j,5){
      rep(k,5){
        b.at(k).at(j)=0;
        if (x-2+k>w || x-2+k<1 || y-2+j>h || y-2+j<1) continue;
        auto it=s.find(make_pair(x-2+k,y-2+j));
        if (it!=s.end()) b.at(k).at(j)=1;
      }
    }  
     
    rep(j,3){
      rep(k,3){
        int u=0;
        if (x+k>w || x-2+k<1 || y+j>h || y+j-2<1) continue;
        rep(jj,3){
          rep(kk,3){
            u+=b.at(k+kk).at(j+jj);
          }
        }
        //cout << "kkkkkkk" << u << " " << i << " " << j << k << endl;
        a.at(u-1)--;
        a.at(u)++;
      }
    }
  }
  rep(i,10){
    cout << a.at(i) << endl;
  }
}
