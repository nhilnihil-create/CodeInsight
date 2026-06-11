#include<iostream>
using namespace std;
int main(){
  int n,a,i,min;long long ans;cin >> n;ans = 0;min = 1;
  for(i=0;i<n;i++){
    cin >> a;
    if (min==a) min = a+1;
    else ans += (a-1)/min;
    if(a != 1 && i == 0) min += 1;
  }
  cout << ans << endl;
}
