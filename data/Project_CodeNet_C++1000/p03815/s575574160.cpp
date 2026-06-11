  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <deque>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)

  
  int main(){
    ll n;
    cin >> n;
    ll ans;
    if (n%11LL > 6 ) ans=(n/11LL)*2+2;
    else if (n%11LL <= 6  && n%11LL >=1) ans=(n/11LL)*2+1;
    else if (n%11LL == 0) ans=(n/11LL)*2;
    cout << ans << endl;
    return 0;
  }
