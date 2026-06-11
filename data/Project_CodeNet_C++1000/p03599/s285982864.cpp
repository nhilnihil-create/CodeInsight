#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  int e, f; cin >> e >> f;
  double conc = 0;
  pair<int,int> ans; 
  ans.first = 100 * a;
  ans.second = 0;
  for(int i = 0; i * 100 * a <= f ;i++){
    for(int j = 0; i * 100 * a + j * 100 * b <= f; j++){
      int water = 100 * a * i + 100 * b * j;
      if(water == 0) continue;
      for(int k = 0; water + k * c <= f; k++){
        for(int l = 0; water + k * c + l * d <= f; ++l){
           int salt = k * c + l * d;
           if(salt > e * water/100) break;
           if(conc < (double)salt/(double)water){
             conc = (double)salt/(double)water;
            //  cout << "i, j, k, l: " << i <<" "<< j<<" " << k <<" "<< l << " "<<conc << endl;
             ans.first = water + salt;
             ans.second = salt;
           }
        }
      }
    }
  }
  cout << ans.first << " " << ans.second << endl;
  return 0; 
}
