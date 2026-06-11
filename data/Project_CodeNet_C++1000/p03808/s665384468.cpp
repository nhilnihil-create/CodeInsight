#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int sum;
Int sumone, n, cnt;
Int a[216000];
void ok(){
  cout << "YES" << endl;
  exit(0);
}

void ng(){
  cout <<  "NO" << endl;
  exit(0);
}


int main(){
  cin >> n;
  for(Int i = 0;i < n;i++)cin >> a[i], sum += a[i];
  sumone = n * (n+1) / 2;
  if(sum % sumone)ng();
  sum /= sumone;
  for(Int i = 0;i < n;i++){
    Int b = (i + n - 1) % n;
    Int diff = a[b] - a[i];
    diff += sum;
    if(diff < 0 || diff % n)ng();
    cnt += diff / n;
  }
  if(sum != cnt)ng();
  ok();
  return 0;
}
