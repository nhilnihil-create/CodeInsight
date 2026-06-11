#include <bits/stdc++.h>

 using namespace std;
 
 int main(){
     int n,m; //都市の数nと道路の数m本
     cin >> n >> m;
     
     int a,b; //都市の番号
     
     vector<int> ans(n,0);
     
     for(int i = 0;i < m;i++){
         cin >> a >> b;
         ans.at(a - 1)++;
         ans.at(b - 1)++;
     }
     
     for(int i = 0;i < n;i++){
         cout << ans.at(i) << endl;
     }
 }
