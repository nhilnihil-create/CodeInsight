#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  LL i,o,t,j,l,s,z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  cout << o+max(i/2*2+j/2*2+l/2*2,(j-1)/2*2+(l-1)/2*2+(i?1:0)*(j?1:0)*(l?1:0)*(3+(i-1)/2*2)) << endl;
  return 0;
}