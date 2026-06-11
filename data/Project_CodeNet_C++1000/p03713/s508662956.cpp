#include <iostream>
using namespace std;
int main(){
  long long x,y;cin>>x>>y;
  if(!(x%3) || !(y%3)){
    cout << 0 << endl;
    return 0;
  }
  long long a = y/2;
  long long b = y/2;
  if(y%2)b++;
  //cout << a << " " << b << endl;
  long long ans = x*y;
  for(long long i = 1; x > i; i++){
    long long mx = max((i*y),max(((x-i)*a),((x-i)*b)));
    long long mn = min((i*y),min(((x-i)*a),((x-i)*b)));
    ans = min(ans,mx-mn);
    //cout << (i*y) << " " << (x-i)*a << " " << (x-i)*b << endl;
  }
  a = x/2;
  b = x/2;
  if(x%2)b++;
  for(long long i = 1; y > i; i++){
    long long mx = max((i*x),max(((y-i)*a),((y-i)*b)));
    long long mn = min((i*x),min(((y-i)*a),((y-i)*b)));
    ans = min(ans,mx-mn);
    //cout << (i*x) << " " << (y-i)*a << " " << (y-i)*b << endl;
  }
  if(x > 2)ans = min(ans,y);
  if(y > 2)ans = min(ans,x);
  cout << ans << endl;
}