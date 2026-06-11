//  s.at(0) = toupper(s.at(0));//小文字なら大文字へ//大文字の場合はそのまま
//  s.at(i) = tolower(s.at(i));//大文字なら小文字へ//小文字の場合はそのまま
//  string s;
//  cin >> s;
//  cout << s.at(0) <<endl;
//  cout << s.at(0)-'0' <<endl;
//  Aが16？
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
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
    */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  ll a,b,c,d,n;
  cin >> a >> b >> c >> d >> n;
  //1Lについて
  ll oneLma = 0;
  oneLma = min(a*4,b*2);
  oneLma = min(oneLma,c);
  //2Lについて
  ll twoLma = 0;
  twoLma = min(a*8,b*4);
  twoLma = min(twoLma,c*2);
  twoLma = min(twoLma,d);
  
//  cout << oneLma << endl;
//  cout << twoLma << endl;
  if(n==1) cout<<oneLma<<endl;
  else{
    if(n%2==0){
      ll k = n/2;
      cout << twoLma * k << endl;
      return 0;
    }
    else{
      ll k = n/2;
      cout << twoLma * k + oneLma << endl;
      return 0;
    }
  }
}