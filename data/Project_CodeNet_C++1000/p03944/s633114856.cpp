//auto 関数名 = [(&:ラムダ外の引数をとる時))](引数の型1 引数名1, 引数の型2, 引数名2, ...) { 関数の処理 }; //inside main() define function. take care of };
// for (int tmp = 0; tmp < (1 << ビット数); tmp++) {
//   bitset<ビット数> s(tmp);
//   // (ビット列sに対する処理)
// }
// sort(配列変数.begin(), 配列変数.end());
// do {
//   // 順列に対する処理
// } while (next_permutation(配列変数.begin(), 配列変数.end()));
//const double PI = acos(-1); M_PI
// cout << fixed << setprecision(10);
#include <bits/stdc++.h>
#include <regex>
using namespace std;
using ll = int64_t;
using P = pair<int,int>;
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end() //sort(all(vec)); ,reverse(all(vec));etc
int main(){
  int w,h,n;
  cin>>w>>h>>n;
  vector<vector<int>>vec(n,vector<int>(2));
  int num1,num2,num3,num4;
  num1=0;
  num2=w;
  num3=0;
  num4=h;
  int a;
  rep(i,n){
    cin>>vec.at(i).at(0)>>vec.at(i).at(1);
    cin>>a;
    if(a==1){
      if(num1<vec.at(i).at(0)){num1=vec.at(i).at(0);}
    }
    if(a==2){
      if(num2>vec.at(i).at(0)){num2=vec.at(i).at(0);}
    }
    if(a==3){
      if(num3<vec.at(i).at(1)){num3=vec.at(i).at(1);}
    }
    if(a==4){
      if(num4>vec.at(i).at(1)){num4=vec.at(i).at(1);}
    }
    a=0;
  }
  //cout<<num2<<" "<<num1<<" "<<num4<<" "<<num3<<endl;
  if(num2-num1<0||num4-num3<0){
    cout<<0<<endl;
    return 0;
  }
  int t=(num2-num1)*(num4-num3);
  
  cout<<t<<endl;


}


