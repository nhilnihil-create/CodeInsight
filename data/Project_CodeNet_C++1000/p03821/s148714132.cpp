  #include <iostream>
  #include <string>
  #include <vector>
  #include <algorithm>
  #include <utility>
  #include <map>
  using namespace std;
  typedef long long ll;
  #define rep(i,n) for (int i=0;i < (int)(n);i++)


  int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i,n){
      cin >> a[i] >> b[i];
    }
    ll addsum = 0;
    for (int i= n-1;i >= 0;i--){
      ll now = a[i] + addsum;
      if (now%b[i] == 0) continue;
      addsum += b[i] - now%b[i];
    }
    cout << addsum << endl;
    

    return 0;
  }
