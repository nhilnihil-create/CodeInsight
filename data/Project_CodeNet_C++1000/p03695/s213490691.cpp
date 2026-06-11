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
  int n;
  cin >> n;
  vector<int>a(n);
  vector<int>b(9);
  int count = 0;
  rep(i,n) cin >> a.at(i);
  rep(i,n){
    if(a.at(i)<=399) b.at(0)++;
    else if(a.at(i)<=799) b.at(1)++;
    else if(a.at(i)<=1199) b.at(2)++;
    else if(a.at(i)<=1599) b.at(3)++;
    else if(a.at(i)<=1999) b.at(4)++;
    else if(a.at(i)<=2399) b.at(5)++;
    else if(a.at(i)<=2799) b.at(6)++;
    else if(a.at(i)<=3199) b.at(7)++;
    else b.at(8)++;
  }
  rep(i,8){
    if(b.at(i)>=1)count++;
  }
//  cout << count << endl;
//  rep(i,9) cout << b.at(i) << " ";
//  cout << endl;
  
  //min
  if(count==0) cout << 1;
  else cout << count;
  
  //kuuhaku
  cout << " ";
  
  //max
  cout << count + b.at(8);
}