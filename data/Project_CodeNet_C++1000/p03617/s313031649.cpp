#include <iostream>
using namespace std;

#define ABS(X) ((X)<0?-(X):(X))
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main(void){
  long long q,h,s,d,n;
  long long ans;
  
  cin >> q >> h >> s >> d >> n;
  s = MIN(s,MIN(q*4,h*2));
  ans = MIN(s*n, n/2*d+(n%2*s));
  cout << ans << endl;
  return 0;
}
