#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n, x;
    cin >> n >> x;
    if(x == 1 || x == 2*n-1){
        cout << "No" <<endl;
        return;
    }
    cout << "Yes" << endl;
    for(ll i = 0; i <2*n-1; ++i){
        if((x+n+i)%(2*n-1) == 0) cout << 2*n-1 << endl;
        else cout << (x+n+i)%(2*n-1) << endl;
    }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //int t;cin>>t;while(t--)
  solve();
  return 0;
}
