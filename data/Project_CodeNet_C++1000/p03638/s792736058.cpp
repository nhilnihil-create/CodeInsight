#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

 
int main(){
  int h, w;
  cin >> h >> w;
  int nh=0, nw=0;
  int m[h][w]={};
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    while(a>0){
      if(nh%2==0){
        a--;
        m[nh][nw] = i+1;
        if(nw+1>=w) nh++;
        else nw++;
      }else{
        a--;
        m[nh][nw] = i+1;
        if(nw-1<0) nh++;
        else nw--;
      }
    }
  }
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}