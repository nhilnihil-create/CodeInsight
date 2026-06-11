#include <iostream>
using namespace std;

#define MAX(X,Y) ((X)>(Y)?(X):(Y))

int main(void){
  long long n, maxa, maxb, ans;
  
  cin >> n;
  maxa = 0;
  for (int i=0; i<n; i++){
    long long a,b; cin >> a >> b;
    maxa = MAX(maxa, a);
    if (a==maxa) maxb = b;
  }
  cout << (maxb+maxa) << endl;
  return 0;
}