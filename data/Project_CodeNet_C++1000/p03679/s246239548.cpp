#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1000000;
#include <map>
#include <math.h>
 
using ll = long long;
using namespace std;

ll n, k;
const ll mod = 1000000007;

int main(){
   int x, a, b;
   cin >> x >> a >> b;

   if(a-b>=0) out("delicious");
   else if(a+x+1-b>0) out("safe");
   else out("dangerous");
}
