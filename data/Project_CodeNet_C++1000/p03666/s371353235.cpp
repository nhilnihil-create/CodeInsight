#include<iostream>
#include<vector>
using namespace std;

typedef long long int ll;

int main(){
  ll n,a,b,c,d; cin >> n >> a >> b >> c >> d;
  bool flag = false;
  for(long long int i=0;i<=n-1;i++){
  	if(a + (i*c) + (n-1-i)*(-d) <= b && b <= a + (i*d) + (n-1-i)*(-c)) flag = true;
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}