#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)

typedef long long ll;
///vector<pair<string, int>>;

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n, 0);
  ll count = 1;
  ll inc =0;
  ll dec = 0;
  rep(i, n) cin >> a[i];

  rep(i, n-1){
    if(a[i+1]-a[i]>0)inc++;
    else if(a[i+1]-a[i]<0) dec++;

    if(dec>0 && inc>0){
      count++;
      
      dec = 0;
      inc = 0;
    }
  }
  
  cout << count << endl;
}


