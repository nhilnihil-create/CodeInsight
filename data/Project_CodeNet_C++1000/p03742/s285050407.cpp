#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL x,y;
  cin >> x >> y;
  if(max(x-y,y-x)<=1) cout << "Brown" << endl;
  else cout << "Alice" << endl;
  return 0;
}
