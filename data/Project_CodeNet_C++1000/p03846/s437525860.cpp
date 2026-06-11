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
  if(n%2 == 0){
    for(auto p : mp){
      if(p.first%2 == 0){
        cout << 0 << endl;
        return 0;
      }
      if(p.second != 2){
        cout << 0 << endl;
        return 0;
      }//if_p.second
    }//for_p
    cout << spow(2,mp.size()) << endl;
    return 0;
  }//if_mp.size
  if(n%2 == 1){
    for(auto p : mp){
      if(p.first == 1){
        cout << 0 << endl;
        return 0;
      }
      if(p.first == 0){
        if(p.second != 1){
          cout << 0 << endl;
          return 0;
        }
      }
      if(p.first > 0){
        if(p.second != 2){
          cout << 0 << endl;
          return 0;
        }
      }
    }
    cout << spow(2,mp.size()-1) << endl;
    return 0;
  }//if_mp.size
}
