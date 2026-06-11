#include <bits/stdc++.h>
using namespace std;

int main(){
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  int nx=sx,ny=sy;
  string ans="R";
  nx++;
  while(nx!=tx){
    nx++;
    ans+="R";
  }
  while(ny!=ty){
    ny++;
    ans+="U";
  }
  nx--;
  ans+="L";
  while(nx!=sx){
    nx--;
    ans+="L";
  }
  while(ny!=sy){
    ny--;
    ans+="D";
  }
  //cout << ans << endl;
  ny--;
  ans+="D";
  while(nx!=tx+1){
    nx++;
    ans+="R";
  }
  while(ny!=ty){
    ny++;
    ans+="U";
  }
  nx--;
  ny++;
  ans+="LU";
  while(nx!=sx-1){
    nx--;
    ans+="L";
  }
  while(ny!=sy){
    ny--;
    ans+="D";
  }
  ans+="R";
  cout << ans << endl;
  return 0;
}