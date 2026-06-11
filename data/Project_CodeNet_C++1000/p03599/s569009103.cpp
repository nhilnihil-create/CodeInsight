#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INFL = 1LL << 60;
 const int INFI = (1 << 30);

 int main() {
     int A, B, C, D, E, F;
     cin >> A >> B >> C >> D >> E >> F;
     int pro, sug;
     double conc_max = - 0.1;

     for (int a = 0; 100 * A * a <= F; a++) {
       for (int b = 0; 100 * B * b <= F; b++) {
         int W_water = 100 * A * a + 100 * B * b;
         int max_sugar = (A * a + B * b) * E;
         for (int c = 0; C * c <= max_sugar; c++) {
           for (int d = 0; D * d <= max_sugar; d++) {
             if (F < W_water + C * c + D * d) continue;
             if (max_sugar < C * c + D * d) continue;
             if (conc_max < 100.0 * (C * c + D * d) / (W_water + C * c + D * d)) {
               pro = W_water + C * c + D * d;
               sug = C * c + D * d;
               conc_max = 100.0 * (C * c + D * d) / (W_water + C * c + D * d);
             }
           }
         }
       }
     }

     cout << pro << " " << sug << endl;
 }
