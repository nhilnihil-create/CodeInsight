#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int dev = 0;
  int ans = 0;
  for(int i = 1; i <= n; i++){
    int tmp = i;
    int canDevide = 0;
    while(tmp>0){
      if(tmp%2!=0) break;
      canDevide++;
      tmp /= 2;
    } 
    if(canDevide>=dev){
      ans = i;
      dev = canDevide;
    }
  }
  cout << ans << endl;
}