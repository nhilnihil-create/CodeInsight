#include<iostream>
#include<vector>

using namespace std;

int main(){
   int n, now, count = 0;

   cin >> n;
   vector<int> ve(n + 1);
   vector<int> memo(n + 1);

   for(int i = 1; i < n + 1; i++) cin >> ve[i];

   now = 1;
   while(now != 2){
      if(memo[now] == 1){
         count = -1;
         break;
      }else{
         memo[now]++;
         now = ve[now];
         count++;
      }
   }

   cout << count << endl;
}