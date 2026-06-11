#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
#define all(x) (x).begin(),(x).end()


int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  A *= 100; B *= 100;

  vector<int> water, sugar;
    for(int a=0; A*a<=F; a++){
      for(int b=0; A*a+B*b<=F; b++){
        int num = A * a + B * b;
        auto it = find(all(water), num);
        if(it == water.end() && num != 0){
          //cout << "a:" << a << " b:" << b << " num:" << num << ln;
          water.push_back(num);
        }
      }
    }
  for(int c=0; C*c<= F/2; c++){
    for(int d=0; C*c+D*d<= F/2; d++){
      int num = C * c + D * d;
      auto it = find(all(sugar), num);
      if(it == sugar.end()){
        sugar.push_back(num);
      }
    }
  }

  sort(all(sugar));

 int maxSum = 0, maxSugar =0; double maxP = 0.0;
 for(int i=0; i<water.size(); i++){
   int wa = water[i];
   for(int j=0; j<sugar.size(); j++){
     int su = sugar[j];
     double sum = wa + su;
     double par = su * 100.0 / wa;
     if(par > E) break;
     if(sum > F) break;
     if(maxP <= par){
       maxSum = sum;
       maxP= par;
       maxSugar = su;
     }
   }
 }

 cout << maxSum << " " << maxSugar << ln;
}
