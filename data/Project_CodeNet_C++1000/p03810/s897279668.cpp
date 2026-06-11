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
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;


Int turn = 0;
string player[2] = {"First", "Second"};

void ok(){
  cout << player[turn] << endl;
  exit(0);
}

void ng(){
  cout <<  player[1^turn] << endl;
  exit(0);
}

Int n, a[216000];

//return gcd(a,b); calc x,y s.t ax + by = g
Int extEuclid(Int a, Int b, Int &x, Int &y){
  if(a == 0){
    x = 0;
    y = 1;
    return b;
  }
  Int g = extEuclid(b % a, a, y, x);
  x -= b/a * y;
  return g;
}

Int gcd(Int x, Int y){
  Int a, b;
  return extEuclid(x, y, a, b);
}


int main(){
  cin >> n;
  for(int i = 0;i < n;i++)cin >> a[i];

  while(true){
    int evencnt = 0;
    for(int i = 0;i < n;i++)evencnt += a[i] % 2 == 0;
    if(evencnt % 2 == 1)ok();
    if(n - evencnt > 1)ng();
    int oddpos = 0;
    while(a[oddpos] % 2 == 0)oddpos++;
    if(a[oddpos] == 1)ng();
    a[oddpos]--;
    Int g = 0;
    for(int i = 0;i < n;i++)g = gcd(g, a[i]);
    for(int i = 0;i < n;i++)a[i] /= g;
    turn ^= 1;
  }
  return 0;
}