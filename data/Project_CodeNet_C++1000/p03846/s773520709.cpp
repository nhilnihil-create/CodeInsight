#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

ll MOD = (ll)pow(10,9)+7;

ll spow(ll a,ll p){
  if(p == 0) return 1;
  if(p == 1) return a;
  return (a*spow(a,p-1))%MOD;
}

int main(){
  int n;
  cin >> n;
  map<int,int> mp;
  rep(i,n){
    int x;
    cin >> x;
    mp[x] ++;
  }
  int m = mp.size();
  if(n%2 == 0){
    if(n != 2*m){
      cout << 0 << endl;
      return 0;
    }
    for(int i=1;i<=2*m-1;i += 2){
      if(mp[i] != 2){
        cout << 0 << endl;
        return 0;
      }
    }
    cout << spow(2,m) << endl;
    return 0;
  }
  if(n%2 == 1){
    if(n != 2*m-1){
      cout << 0 << endl;
      return 0;
    }
    for(int i=0;i<=2*(m-1);i += 2){
      if(i == 0){
        if(mp[i] != 1){
          cout << 0 << endl;
          return 0;
        }
      }//if_mp
      if(i > 0){
        if(mp[i] != 2){
          cout << 0 << endl;
          return 0;
        }
      }//if_mp
    }//for_i
    cout << spow(2,m-1) << endl;
    return 0;
  }//if_m%2
}
