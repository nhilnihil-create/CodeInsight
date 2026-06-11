#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

int mp[250011];

int main(){

  REP(i,250011)mp[i] = -1;

  int n;cin >> n;
  vector<pair<int,int>> v;

  REP(i,n){
    int tmp;cin >> tmp;
    tmp--;
    v.PB(MP(tmp,i+1));
    if(mp[tmp] != -1){
      cout << "No" << endl;
      return 0;
    }
    mp[tmp] = i+1;
  }

  sort(ALL(v));
  int cou = 0;

  REP(i,n){
    REP(j,v[i].SE-1){
      while(mp[cou] != -1)cou++;
      mp[cou] = v[i].SE;
      if(cou > v[i].FI){
        cout << "No" << endl;
        return 0;
      }
      cou++;
    }
  }

  REP(i,n){
    for(int j = v[i].SE + 1;j <= n;j++){
      while(mp[cou] != -1)cou++;
      if(cou < v[i].FI){
        cout << "No" << endl;
        return 0;
      }
      mp[cou] = v[i].SE;
      cou++;
    }
  }

  cout << "Yes" << endl;
  REP(i,n*n)cout << mp[i] << " ";
  cout << endl;



	return 0;
}
