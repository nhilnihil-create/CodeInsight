#include <bits/stdc++.h>
using namespace std;
const int64_t INF=9999999999999999;

int main() {
 int H,W;
 vector<vector<char>>C(200,vector<char>(200));
 vector<vector<char>>K(400,vector<char>(400));
   cin>>H>>W;
   for(int i=1;i<=H;i++){
      for(int j=1;j<=W;j++){
         cin>>C[i][j];
      }
   }
   for(int i=1;i<=2*H;i++){
      for(int j=1;j<=W;j++){
         K[i][j]=C[(i+1)/2][j];
      }
   }
   for(int i=1;i<=2*H;i++){
      for(int j=1;j<=W;j++){
         cout<<K[i][j];
      }
      if(i<=2*H-1){cout<<endl;}
   }
return 0;}