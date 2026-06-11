//  cout << char(i+48) << endl;//なぜかaは47と得る時がある。+48で出力もaにできる。
//  cout << char(97) << endl;//アスキーコードでaを出力
// sort(b.begin(), b.end());//bという配列を小さい方からソート
// reverse(b.begin(), b.end());//bという配列をリターン
// 10桁でdouble出力するパターン１ 
// printf("%.10f\n", ma);
// 10桁でdouble出力するパターン２
//cout << fixed << setprecision(10);
//  cout << ma << endl;

/*01 02 03 12 13 23　と６回見ていくパターン 
for(int i=0;i<n-1;i++){
  for(int j=i+1;j<n;j++){
    }
  }
*///vector<vector<int>> data(3, vector<int>(4));//int型の2次元配列(3×4要素の)の宣言
//int64_t a;
//10のi乗pow(10, i);
//10の1/2乗（ルート）pow(10, 0.5)
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
    */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  ll n,m;
  cin >> n >> m;
  vector<ll>a(n);
  vector<ll>b(n);
  rep(i,n) cin >>a.at(i) >>b.at(i);
  vector<ll>c(m);
  vector<ll>d(m);
  rep(i,m) cin >> c.at(i)>>d.at(i);
  for(int i=0;i<n;i++){
    int  mi = abs(a.at(i) - c.at(0) ) + abs(b.at(i) - d.at(0));
    int bangou  = 1;
      for(int k=1;k<m;k++){
       int  num = abs(a.at(i) - c.at(k) ) + abs(b.at(i) - d.at(k));
        if(mi > num){
          mi = num;
          bangou = k + 1;
        }
      }
    cout << bangou << endl;
  }
}