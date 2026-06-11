#include<bits/stdc++.h>
using namespace std;

int main(void){
   int H,W;
   cin>>H>>W;
   vector<vector<char>> C(H,vector<char>(W));
   for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
         cin>>C[i][j];
      }
   }
   vector<vector<char>> result(2*H,vector<char>(W));
   for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
         result[i*2][j]=C[i][j];
         result[2*i+1][j]=C[i][j];
      }
   }
   for(int i=0;i<2*H;i++){
      for(int j=0;j<W;j++){
         cout<<result[i][j];
      }
      cout<<endl;
   }
   return 0;
}

