#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
   int h, w, n, now_h, now_w, count, flag;

   cin >> h >> w;
   cin >> n;

   vector<vector<int>> v(h, vector<int>(w));

   now_h = 0;
   now_w = 0; 
   flag = 0;//右方向：0 左方向：1
   for(int i = 0; i < n; i++){
      cin >> count;
      while(count > 0){
         v[now_h][now_w] = i + 1;
         if(flag == 0 && now_w == w - 1){
            now_h++;
            flag = 1;
         }else if(flag == 1 && now_w == 0){
            now_h++;
            flag = 0;
         }else{
            if(flag == 0){//右方向に進んでいる時
               now_w++;
            }else{//左方向
               now_w--;
            }
         }
         count--;
      }
   }

   for(auto i : v){
      for(auto j : i){
         cout << j << ' ';
      }
      cout << endl;
   }
}