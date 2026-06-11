#include <bits/stdc++.h>
using namespace std;
#define REP(i,x,n) for(int i = x; i < n; i++)
#define MAX 100
#define INF 1000000001

// enum {
//   AST_INT,
//   AST_SYM,
//   AST_STR,
//   AST_FUNCALL,
// };



// double winProb(int Rp, int Rq) {
//     return 1/(1+pow(10, (Rq-Rp)/400.));
// }

// int R[1<<10];
// double dp[12][1<<10];
int n,m;
vector<long long> x;
vector<long long> y;

int main() {
   cin >> n >> m;
   
   REP(i,0,n) {
       int tmp;
       cin >> tmp;
       x.push_back(tmp);
   }
   REP(i,0,m) {
       int tmp;
       cin >> tmp;
       y.push_back(tmp);
   }
   
//   cout << (n-1) * (m-1) << endl;
   
   sort(x.begin(),x.end());
   sort(y.begin(),y.end());
   
   long long sum_x = 0;
   REP(k,0,n) {
       sum_x += k*x[k] - (n-1-k)*x[k];
    //   cout << sum_x << endl;
   }
   
   long long sum_y = 0;
   REP(k,0,m) {
       sum_y += k*y[k] - (m-1-k)*y[k];
   }
   
//   cout << sum_x << endl;
   cout << ((sum_x % 1000000007) * (sum_y % 1000000007)) % 1000000007 << endl;
   
}