#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define MOD 1000000007

long comb[100][100] = {};

void init_comb(){
  comb[0][0] = 1;
  comb[1][0] = 1;
  comb[1][1] = 1;
  for(int i=2;i<100;i++){
    for(int j=0;j<=i;j++){
      if(j==0 || j==i) comb[i][j] = 1;
      else comb[i][j] = comb[i-1][j-1]+comb[i-1][j];
    }
  }
}

int main(){
  init_comb();
  fix20;
  int n;
  int a,b;
  cin >> n >> a >> b;
  vector<long> data(n);
  rep(i,n) cin >> data.at(i);
  sort(data.begin(),data.end(),greater<long>());
  long comp = data.at(0);
  int id = 0;
  vector<int> cnt(n,0);
  rep(i,n){
    if(data.at(i) == comp){
      cnt.at(id)++;
    }else{
      comp = data.at(i);
      id++;
      cnt.at(id)++;
    }
  }
  double sum = 0;
  rep(i,a){
    sum += (double)data.at(i);
  }
  cout << sum / ((double)a) << endl;
  long ans = 0;
  if(cnt.at(0) > a){
    for(int i=a;i<=min(cnt.at(0),b);i++){
      ans += comb[cnt.at(0)][i];
    }
  }else{
    int tmp = a;
    rep(i,n){
      tmp -= cnt.at(i);
      if(tmp <= 0){
        cout << comb[cnt.at(i)][tmp+cnt.at(i)] << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
}
