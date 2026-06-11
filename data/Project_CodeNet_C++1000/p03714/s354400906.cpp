#include <bits/stdc++.h>
// atoi : atoi(変数名.c_str())
// to_string(数値)
// %0桁数d とすると表示桁数が「桁数」に満たない場合に0埋めされる
// find(): int i = 変数名.find(“文字列”) 何番目にあるかを得る
// cout << (条件 ? "Yes" : "No") << endl;
// printf("%02d:%02d:%02d",hour,minute,second);
// 降順 sort(a.begin(),a.end(),greater<int>());
// bitset<ビット数> 変数名;  // すべてのビットが0の状態で初期化される
// bitset<ビット数> 変数名("ビット列");  // 指定したビット列で初期化される
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

int main(){
  int n;
  cin >> n;
  vector<long> a(3*n);
  rep(i,3*n) cin >> a.at(i);
  priority_queue<long, vector<long>, greater<long>> begin;
  priority_queue<long> end;
  vector<long> maxi(n+1,0);
  vector<long> mini(n+1,0);
  rep(i,n){
    begin.push(a.at(i));
    maxi.at(0) += a.at(i);
    end.push(a.at(3*n-1-i));
    mini.at(0) += a.at(3*n-1-i);
  }
  //cout << "check" << endl;
  for(int i=1;i<=n;i++){
    long tmp = begin.top();
    maxi.at(i) = maxi.at(i-1);
    //cout << "check" << i << endl;
    if(a.at(n-1+i) > tmp){
      maxi.at(i) += a.at(n-1+i) - tmp;
      begin.pop();
      begin.push(a.at(n-1+i));
    }
    //cout << "check" << i << endl;
    long tmp1 = end.top();
    mini.at(i) = mini.at(i-1);
    if(a.at(2*n - i) < tmp1){
      mini.at(i) -= tmp1 - a.at(2*n - i);
      end.pop();
      end.push(a.at(2*n - i));
    }
    //cout << "check" << i << endl;
  }
  //cout << "check" << endl;
  long ans = -1e15;
  rep(i,n+1){
    ans = max(ans,maxi.at(i)-mini.at(n-i));
    //cout << ans << endl;
  }
  cout << ans << endl;
}