#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
  ll n;
  cin >> n;
  vector<ll> a(100100, 0);
  rep(i, n){
    ll tmp;
    cin >> tmp;
    if(tmp)  
      a[tmp-1]++; 
    a[tmp]++, a[tmp+1]++;
  }
  cout << *max_element(a.begin(), a.end()) << endl;
}
