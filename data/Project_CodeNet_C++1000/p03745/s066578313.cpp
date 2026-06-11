#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  
  int up = 0, down = 0,same = 0;
  int ans = 1;
  for(int i = 1; i < n; i++){
    if(a[i] > a[i-1]){
      up = 1;
      same = 0;
    }else if(a[i] < a[i-1]){
      down = 1;
      same = 0;
    }else{
      same = 1;
    }
    
    if( (up == down) && (same != 1) ){
      up = 0;
      down = 0;
      same = 0;
      ans++;
    }
  }//for
  
  cout << ans << endl;
}