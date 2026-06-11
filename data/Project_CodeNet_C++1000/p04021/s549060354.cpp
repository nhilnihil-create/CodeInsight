// 質問用
// 詳しい質問は39行目から始まります
#include<iostream>
#include<algorithm>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
/* 方針:操作2は(i-j)%2==0なる
i番目とj番目のみを交換できるので、
偶数番目同士、奇数番目同士では自由に交換できるが
1,3,5…番目と2,4,6…番目の間では操作1でしか交換ができず
よって、a[i]の値を小さい順に0,1,…n-1で置き換え、
a[i](添え字は0〜n-1)とiの
偶奇が違うところの数を数えて2で割れば解ける
(ここが違っていたら教えてください) */
int main(){
  int n,ans=0; cin>>n;
  /* 名前の通り、与えられたa(この後ソートされる)
　　　、もともとのaを保管するためのmoto、
     座標圧縮後の配列zaatuを用意する*/
  int a[n],moto[n],zaatu[n];
  rep(i,n){
    cin>>a[i];
    moto[i]=a[i];
  }
  sort(a,a+n);
  /*mapを用いて小さい順にa[i]の値にiを対応づける*/
  map<int,int> mp;
  rep(i,n){
    mp[a[i]]=i;
  }
  /*作った対応をもとに配列motoを0〜n-1に置き換える*/
  rep(i,n){
    zaatu[i]=mp[moto[i]];
  }
  /*zaatu[i]とiの偶奇が違うところを数えたい…けれど*/
  rep(i,n){
    int x=zaatu[i];
  /*ここでエラーが発生します
  (zaatu[i]をa[i]に置き換えるとREは消えます)
  ここでエラーが発生する原因が分かりません。
  どなたか教えていただけないでしょうか。*/
    if(x%2!=i%2){
      ans++;
    }
  }
  cout<<ans/2;
}
