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
  int w,h,n;
  cin >> w >> h >> n;
  vector<int>x(n);
  vector<int>y(n);
  vector<int>a(n);
  rep(i,n) cin >> x.at(i) >> y.at(i) >> a.at(i);
  int num = w * h;
  int count = 0;
  vector<vector<int>> data(w, vector<int>(h));//int型の2次元配列(3×4要素の)の宣言  
  rep(i,n){
    if(a.at(i) == 1 ){
      for(int j = 0;j<x.at(i);j++){
        for(int k=0;k<h;k++){
          data.at(j).at(k)++;
        }
      }
    }
    else if(a.at(i)==2){
      for(int j = x.at(i);j<w;j++){
        for(int k=0;k<h;k++){
          data.at(j).at(k)++;
        }
      }
    }
    else if(a.at(i)==3){
      for(int j = 0;j<w;j++){
        for(int k=0;k<y.at(i);k++){
          data.at(j).at(k)++;
        }
      }
    }
    else{
      for(int j = 0;j<w;j++){
        for(int k=y.at(i);k<h;k++){
          data.at(j).at(k)++;
        }
      }
    }
  }//repend
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(data.at(i).at(j) >=1){
        count ++;
//        cout<<data.at(i).at(j);
      }
//      else cout<<"0";
//      if(data.at(i).at(j) >= 1 )count++;
    }
//    cout << endl;
  }
  cout << num-count << endl;
}