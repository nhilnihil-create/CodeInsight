#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> v1;
typedef vector<v1> v2;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll mod = 1000000007;
const ll INF = 1ll << 50;


ll h,w;
string a[101];
ll cnt[128];

void error(){
  cout << "No" << endl;
  exit(0);
}

int main(){
  cin >> h >> w;
  for(ll i = 0;i < h;i++) cin >> a[i];
  for(ll i = 0;i < h;i++){
    for(ll j = 0;j < w;j++){
      cnt[a[i][j]]++;
    }
  }
  if(h%2 == 0 && w%2 == 0){
    for(ll i = 0;i < 128;i++){
      if(cnt[i]%4 != 0) error();
    }
  }else if(h%2 == 1 && w%2 == 1){
    ll odd = 0;
    ll even = 0;
    for(ll i = 0;i < 128;i++){
      if(cnt[i]%4 != 0){
        if(cnt[i]%2 == 0){
          even++;
        }else{
          odd++;

        }
      }
    }
    if(even*2 > h-1+w-1) error();
    if(odd != 1) error();
  }else if(h%2 == 1){
    ll odd = 0;
    ll even = 0;
    for(ll i = 0;i < 128;i++){
      if(cnt[i]%4 != 0){
        if(cnt[i]%2 == 0){
          even++;
        }else{
          odd++;

        }
      }
    }
    if(even*2 > w) error();
    if(odd != 0) error();
  }else if(w%2 == 1){
    ll odd = 0;
    ll even = 0;
    for(ll i = 0;i < 128;i++){
      if(cnt[i]%4 != 0){
        if(cnt[i]%2 == 0){
          even++;
        }else{
          odd++;

        }
      }
    }
    if(even*2 > h) error();
    if(odd != 0) error();
  }
  cout << "Yes" << endl;

}
