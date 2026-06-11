// sort(b.begin(), b.end());//bという配列を小さい方からソート
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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  int64_t n;
  cin >> n;
  int64_t Acount=0;
  int64_t Bcount=0;
  int64_t sum =0;
  vector<int> a(n);
  rep(i,n) cin >> a.at(i);
  int64_t sumA =0;
  int64_t sumB =0;
  int64_t num = 0;

//+-+- となるApata-nn
  for(int i=0;i<n;i++){//roop
    if(i%2==0){
      sumA += a.at(i);
      if(sumA<=0){
        num = 1 - sumA;
        sumA += 1-sumA;
        Acount += abs(num);
      }
    }
    else{
      sumA += a.at(i);
      if(sumA>=0){
        num = -1-sumA;
        sumA += -1-sumA;
        Acount += abs(num);
      }
    }
  }//roopend
//-+-+ となるBpata-nn
  for(int i=0;i<n;i++){
    if(i%2==0){
      sumB += a.at(i);
      if(sumB>=0){
        num = -1-sumB;
        sumB += -1-sumB;
        Bcount += abs(num);
      }
    }
    else{
      sumB += a.at(i);
      if(sumB<=0){
        num = 1 - sumB;
        sumB += 1-sumB;
        Bcount += abs(num);
      }
    }
  }
  if(Acount > Bcount) cout << Bcount << endl;
  else cout<< Acount << endl;
}