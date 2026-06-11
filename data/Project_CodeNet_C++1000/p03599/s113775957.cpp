#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll wa,wb,sa,sb,lim,sum;
  cin >> wa >> wb >> sa >> sb >> lim >> sum;
  vec w,s;
  for(ll i=0;i*wa*100<=sum;i++) {
    for(ll j=0;(i*wa+j*wb)*100<=sum;j++) {
      if(i==0&&j==0) continue;
      w.push_back(i*wa+j*wb);
    }
  }
  for(ll i=0;i*sa<=sum;i++) {
    for(ll j=0;i*sa+j*sb<=sum;j++) {
      s.push_back(i*sa+j*sb);
    }
  }
  sort(w.begin(),w.end());
  sort(s.begin(),s.end());
  ll as=0,aw=w[0];
  for(ll i=0;i<w.size();i++) {
    for(ll j=0;j<s.size();j++) {
      if(w[i]*lim<s[j]||w[i]*100+s[j]>sum) break;
      if(as*w[i]<s[j]*aw) {
        as=s[j];
        aw=w[i];
      }
    }
  }
  cout << aw*100+as << " " << as << endl;
}