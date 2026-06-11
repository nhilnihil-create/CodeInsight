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
 vector<vector<char>> a(h+2,vector<char>(w+2));
 rep(i,h+2){
    rep(j,w+2){
       if(i==0 ||i==h+1){
          a.at(i).at(j)='#';
       }
       else if(j==0 || j==w+1){
          a.at(i).at(j)='#';
       }
    }
 }
 for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
       cin >> a.at(i).at(j);
    }
 }
 rep(i,h+2){
    rep(j,w+2){
       cout << a.at(i).at(j);
    }
    cout << endl ;
 }
}
    