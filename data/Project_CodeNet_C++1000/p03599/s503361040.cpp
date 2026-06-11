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
 double a,b,c,d,e,f;
 cin>>a>>b>>c>>d>>e>>f;
 double maxs=0;
 double maxsw=a*100;
 double sugar;
 double water;
 rep(i,3000){
   rep(j,3000){
     sugar=i*c+j*d;
     if((sugar*(100+e)/e)>f){continue;}
     rep(n,30){
       rep(m,30){
         water=n*a*100+m*b*100;
         if(water==0){continue;}
         if(sugar+water>f){
           continue;
         }
         if(sugar>(double)(e*water/(double)(100))){
           continue;
         }
         if((sugar/(sugar+water))>(maxs/maxsw)){
           //cout<<i<<j<<sugar<<" "<<sugar+water<<endl;
           maxs=sugar;
           maxsw=sugar+water;
         }
       }
     }
   }
 }
 cout<<maxsw<<" "<<maxs<<endl;
}


