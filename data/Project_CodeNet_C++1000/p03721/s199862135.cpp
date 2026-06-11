#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define repp(i,n) for((i)=1;(i)<=(n);(i)++)
int main(){
  ll i,n,k,c[100010]={0},a,b,cnt=0;
  cin >> n >> k;
  rep(i,n){
    cin >> a >> b;
    c[a] += b;
    cnt += b;
  }
  repp(i,100000){
    k -= c[i];
    if(k<=0){
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}