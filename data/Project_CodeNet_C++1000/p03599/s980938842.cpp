#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
  a *= 100;
  b *= 100;
  int maxy = 0, maxz = a, x, y, z;
  for(int i = 0; a * i <= f; i++){
    for(int j = 0; a * i + b * j <= f; j++){
      for(int k = 0; a * i + b * j + c * k <= f; k++){
        for(int l = 0; a * i + b * j + c * k + d * l <= f; l++){
          int x = a * i + b * j;
          int y = c * k + d * l;
          int z = x + y;
          //if(z == 2634) cout << i << " " << j << " " << k << " " << l << endl;
          //cout << z << endl;
          if(x == 0) continue;
          if(z > f) break;
          if((x / 100) * e < y) break;
          if(y * 100 * maxz > maxy * 100 * z){
            maxy = y;
            maxz = z;
          }
        }
      }
    }
  }
  cout << maxz << " " << maxy << endl;
  return;
}

int main(){
  solve();
  return 0;
}
