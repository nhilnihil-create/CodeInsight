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
  int n,m;
  cin >> n >> m;
  vector<string>a(n);
  vector<string>b(m);
  rep(i,n) cin >> a.at(i);
  rep(i,m) cin >> b.at(i);
  int itti = m*m;
  vector<vector<char>> s(n, vector<char>(n));//int型の2次元配列(3×4要素の)の宣言
  vector<vector<char>> t(m, vector<char>(m));//int型の2次元配列(3×4要素の)の宣言
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      s.at(i).at(j) = a.at(i).at(j);
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      t.at(i).at(j) = b.at(i).at(j);
    }
  }
/*
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << s.at(i).at(j);
    }
    cout << endl;
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      cout << t.at(i).at(j);
    }
    cout << endl;
  }
  */
  int flag=0;
  int count = 0;
  for(int i=0;i<n-m+1;i++){
    for(int j=0;j<n-m+1;j++){
      for(int k=0;k<m;k++){
        for(int p=0;p<m;p++){
          if(s.at(i+k).at(j+p) == t.at(k).at(p)) count++;
        }
      }
      if(count == itti) flag=1;
      count = 0;
    }
  }
  if(flag==1) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
