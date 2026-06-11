#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 

using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<char>> vec(h+1,vector<char>(w+1));
  for(int i=1;i<=h;i++)for(int j=1;j<=w;j++)cin>>vec[i][j];
  rep(i,h+2)rep(j,w+2){
    if(i==0||i==h+1||j==0||j==w+1)cout<<'#';
    else cout<<vec[i][j];
    if(j==w+1)cout<<endl;
  }
}