#include <bits/stdc++.h>

 using namespace std;
 
 int main(){
     int n; //n個のボタン
     cin >> n;
     vector<int> bt;
     for(int i = 0;i < n;i++){
         int a; //ボタンの出力先
         cin >> a;
         a--;
         bt.push_back(a);
     }
     
     int now = 0; int c = 0; //ボタンを押した回数がcount nowが現在光っているボタンの位置(添え字)
     for(;;){
         //二番目のボタンの位置の時
         if(now == 1){
             cout << c << endl;
             break;
         }
         
         //カウント数がボタン数を超えたら-1　同じ値を繰り返し出しているため、now = 1に到達できないから
         if(c >= n){
             cout << -1 << endl;
             break;
         }
         c++;
         //光っているボタンの現在位置を更新する。
         now = bt[now];
     }
     
 }
