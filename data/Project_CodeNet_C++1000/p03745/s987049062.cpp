#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n;
   cin >> n;
   vector <int> a(n);
   for(auto &e: a) cin >> e;

   vector <vector <int>> dp(n, vector <int> (2));
   dp[0][0] = 1;
   dp[0][1] = 1;

   // 0 -> increasing
   for(int i = 1; i < n; i++) {
      if(a[i] > a[i - 1]) {
         dp[i][0] = dp[i - 1][0];
         dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      } else if(a[i] < a[i - 1]){
         dp[i][1] = dp[i - 1][1];
         dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
      } else {
         dp[i][0] = dp[i - 1][0];
         dp[i][1] = dp[i - 1][1];
      }
   }
   cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
}

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solveCase();
   }
 
   return 0;
}