#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int H,W;
    cin>>H>>W;
     vector<vector<char>> A(H, vector<char>(W));
  	rep(i,H){
      rep(j,W){
        cin>>A[i][j];
      }
    }
     rep(i,H+2){
         rep(j,W+2){
             if(i==0||i==H+1){
                 cout<<"#";
             }
            else if(j==0||j==W+1){
                cout<<"#";
            }
            else{
                cout<<A[i-1][j-1];
            }
         }
         cout<<""<<endl;
     }
}
