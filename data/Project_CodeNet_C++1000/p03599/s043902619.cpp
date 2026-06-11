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
  double a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  double noudo = e / (e+100);
//  cout << noudo <<endl;
  int num =0;
  int num2 = 0;
  double ndcheck=0;
  double stcheck=0;
  double hanteinoudo = 0;
  for(int i=0;i<f/100;i++){
    for(int j=0;j<f/100;j++){
      if(i == 0 && j == 0);
      else if(i*a*100 + j*b*100 >=f);
      else{
        for(int k=0;k>-1;k++){
          for(int m=0;m>-1;m++){
            ndcheck = (k*c + m*d)/(i*a*100 + j*b*100 + k*c + m*d);
            stcheck = i*a*100 + j*b*100 + k*c + m*d;
            if(ndcheck <= noudo && stcheck <= f){
              if(ndcheck >= hanteinoudo){
                hanteinoudo = ndcheck;
                num = stcheck;
                num2 =  k*c + m*d;
              }
            }
            else break;
          }
          ndcheck = (k*c )/(i*a*100 + j*b*100 + k*c );
          stcheck = i*a*100 + j*b*100 + k*c ;
          if(ndcheck <= noudo && stcheck <= f);
          else break;
        }
      }
    }
  }
    cout << num << " " << num2 << endl;
}