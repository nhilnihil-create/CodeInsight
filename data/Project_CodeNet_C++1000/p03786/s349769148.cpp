#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;

int main() {
  int n;
  cin>>n; 
  vector<ll>a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(a.begin(),a.end()); 
  int co=0;
  rep2(i,1,n){
    a[i]+=a[i-1];
  }
  rep2(i,1,n){
    if(a[i]>3*a[i-1]){
      co=i;
    }
  }
  cout<<n-co<<endl;
}