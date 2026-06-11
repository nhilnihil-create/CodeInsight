#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
   int n, m, a, b, flag;
   string s = "IMPOSSIBLE";

   cin >> n >> m;

   vector<int> ve(200001);

   flag = 0;
   for(int i = 0; i < m; i++){
      cin >> a >> b;
      if(flag == 0){
         if(a == 1){
            if(ve[b] == 0){
               ve[b]++;
            }else{
               s = "POSSIBLE";
               flag = 1;
            }
         }
         if(b == n){
            if(ve[a] == 0){
               ve[a]++;
            }else{
               s = "POSSIBLE";
               flag = 1;
            }
         }
      }
   }
   cout << s << endl;
}