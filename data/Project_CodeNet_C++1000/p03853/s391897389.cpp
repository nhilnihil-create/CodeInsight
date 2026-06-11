#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
   int h,w;
   cin >> h >> w;
   vector<vector<char>> c(h,vector<char>(w));
   rep(i,h){
     rep(j,w){
       cin >> c.at(i).at(j);
     }
   }
   vector<vector<char>>  cc(2*h,vector<char>(w));
   rep(i,2*h){
     rep(j,w){
       cc.at(i).at(j)=c.at(i/2).at(j);
     }
   }
    rep(i,2*h){
     rep(j,w){
       cout << cc.at(i).at(j);
     }
     cout << endl;
   }
}