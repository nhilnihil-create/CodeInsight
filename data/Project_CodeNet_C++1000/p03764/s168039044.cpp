#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

long long x[100000];
long long y[100000];
long long MOD = 1000000007;
long long cum_sum_x[100000];
long long cum_sum_y[100000];
int main(){
    int n;
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    for(int i = 0; i < m; i++){
        cin >> y[i];
    }

   long long x_ans = 0;
   for(int i = 0; i < n; i++){
       x_ans = (x_ans + x[n - 1 - i] * (n - 1 - i)) % MOD;
       x_ans = ((x_ans - x[n - 1 - i] * i) % MOD + MOD) % MOD;
   }
   long long y_ans = 0;
    for(int i = 0; i < m; i++){
       y_ans = (y_ans + y[m - 1 - i] * (m - 1 - i)) % MOD;
       y_ans = ((y_ans - y[m - 1 - i] * i) % MOD + MOD) % MOD;
   }
   cout << (x_ans * y_ans) % MOD << endl;

    return 0;
}
