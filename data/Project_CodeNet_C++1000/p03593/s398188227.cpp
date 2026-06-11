#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>a
#define pb push_back

#define mp make_pair
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll keta(ll n){
  string s = to_string(n);
  ll num = s.size();
  return num;
}

const ll INF = 1LL << 60;

const int dh[4] = {1,0,-1,0};
const int dw[4] = {0,1,0,-1};

struct Edge{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w){}
};
using Graph = vector<vector<Edge>>;
using P = pair<ll, int>;


int main(){
  int H,W; cin >> H >> W;
  vector<string> a(H);
  rep(h,H) cin >> a[h];
  int cnt_4 = (H/2)*(W/2);
  int cnt_1 = (H*W)%2;
  int cnt_2 = (H*W - 4*cnt_4 - cnt_1)/2;

  map<char,int> C;
  rep(h,H) rep(w,W) {
    C[a[h][w]]++;
  }
  
  for(auto c : C) {
    int num = c.second;
    
    while(num/4 > 0 && cnt_4 > 0){
      num -= 4;
      cnt_4--;
    }
    while(num/2 > 0 && cnt_2 > 0){
      num -= 2;
      cnt_2--;
    }
    while(num > 0 && cnt_1 > 0){
      num -= 1;
      cnt_1--;
    }
  }
  if(cnt_1 == 0 && cnt_2 == 0 && cnt_4 == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}