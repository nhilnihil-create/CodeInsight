#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,x;
  cin >> n >> x;
  if(x==2*n-1||x==1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<ll> a(2*n-1);
  set<ll> al;
  a[n-1]=x;
  a[n-2]=1;
  a[n]=2*n-1;
  al.insert(x);
  al.insert(1);
  al.insert(2*n-1);
  if(n>2) {
    if(x!=2*n-2) {
      a[n-3]=2*n-2;
      al.insert(2*n-2);
    }
    else {
      a[n+1]=2;
      al.insert(2);
    }
  }
  ll temp=1;
  for(ll i=0;i<2*n-1;i++) {
    while(al.count(temp)) {
      temp++;
    }
    if(a[i]==0) {
      a[i]=temp;
      temp++;
    }
  }
  for(ll i=0;i<2*n-1;i++) {
    cout << a[i] << endl;
  }
}