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
  string A,B,C;
  cin >> A >> B >> C;
  int acnt = 0;
  int bcnt = 0;
  int ccnt = 0;
  A += 'k';
  B += 'k';
  C += 'k';
  char ch = A.at(0);
  for(;;){
    if(ch == 'k')break;
    if(ch == 'a'){
      acnt++;
      ch = A.at(acnt-1);
    }
    if(ch == 'b'){
      bcnt++;
      ch = B.at(bcnt-1);
    }
    
    if(ch == 'c'){
      ccnt++;
      ch = C.at(ccnt-1);
    }
  }
  if(acnt == A.size() ) cout<<"A"<<endl;
  else if(bcnt == B.size() ) cout<<"B"<<endl;
  else cout<<"C"<<endl;
}
