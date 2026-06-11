#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  
  sort(a.begin(),a.end());
  
  vector<ll> b(n);
  b[0]=a[0];
  for(int i=1;i<n;i++) b[i]=a[i]+b[i-1];
  
  for(int i=n-2;i>=0;i--){
    if(b[i]*2>=a[i+1]) continue;
    else{
      cout << n-i-1 <<endl;
      return 0;
    }
  }
  cout << n << endl;
}