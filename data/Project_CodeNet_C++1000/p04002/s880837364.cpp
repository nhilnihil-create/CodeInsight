#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 1010;

ll H, W, n;

map<int, set<pair<int,int>>> mp;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>H>>W>>n;
  for (int i=0; i<n; i++) {
    int a, b; cin>>a>>b;
    //g[a-1][b-1]++;
    mp[a].insert({b,1});
  }

  // for (int i=0; i<H; i++) {
  //   for (int j=0; j<W; j++) {
  //     cout<<g[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }


  map<int, set<pair<int,int>>> _mp = mp;

  for (auto& p: mp) {
    int a = p.first;
    for (auto& x: p.second) {
      int b = x.first;
      for (int i=-2; i<=2; i++) {
	for (int j=-2; j<=2; j++) {
	  int da = a+i; int db = b+j;
	  if (da<=0 || da>H || db<=0 || db>W) continue;
	  if (_mp[da].count({db,1})) continue;
	  _mp[da].insert({db,0});
	}
      }
    }
  }

  swap(mp, _mp);
  ll all = (H-2)*(W-2);
  vector<ll> freq(10, 0);

  for (auto& p: mp) {
    int a = p.first;
    if (a+2>H) continue;
    for (auto& q: p.second) {
      int b = q.first;
      if (b+2>W) continue;

      int cnt = 0;
      for (int i=0; i<3; i++) {
	for (int j=0; j<3; j++) {
	  int da = a+i; int db = b+j;
	  if (!mp.count(da)) continue;
	  if (mp[da].count({db,1})) cnt++;
	}
      }
      //cout<<a<<" "<<b<<": "<<cnt<<endl;
      if (cnt) freq[cnt]++;
    }
  }

  // cout<<endl;
  // for (int i=0; i<H; i++) {
  //   for (int j=0; j<W; j++) {
  //     cout<<g[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }


  for (int i=1; i<=9; i++) {
    all -= freq[i];
  }

  freq[0] = all;

  for (ll x: freq) {
    cout<<x<<endl;
  }

  return 0;
}
