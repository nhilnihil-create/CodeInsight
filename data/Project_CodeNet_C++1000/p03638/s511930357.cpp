#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define SIZE_OF_ARRAY(ar) (sizeof(ar)/sizeof(ar[0])) 
int main(){
  int h,w,n,a=0;
  cin>>h>>w>>n;
  int hw[h][w];
  int m[n];
  rep(i,n)
     cin>>m[i];
  rep(i,h)rep(j,w){
     if(!m[a])
       a++;
     hw[i][j]=a+1;
     m[a]--; 
  }
  rep(i,h/2+h%2)
    reverse(hw[i*2],hw[i*2]+SIZE_OF_ARRAY(hw[i*2]));
  rep(i,h){
    rep(j,w)
      printf("%d ",hw[i][j]);
    printf("\n");
  }
  return 0;
}