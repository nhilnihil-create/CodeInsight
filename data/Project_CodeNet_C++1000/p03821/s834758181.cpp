//a[n-1]<-a[0]へ移動
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<ll> a(n),b(n);
  rep(i,n) cin>>a[i]>>b[i];
  reverse(all(a));
  reverse(all(b));
  long long plus=0;
  rep(i,n){
    a[i]+=plus;
    if(a[i]%b[i]!=0){
     // plus++;
     // a[i]++;
      int c=b[i]-(a[i]%b[i]);
      plus+=c;
      
    }
    
  }
  cout<<plus<<endl;
}


