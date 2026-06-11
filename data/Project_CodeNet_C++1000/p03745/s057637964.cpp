#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 100100100;

 
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int ans=0;
  rep(i,n){
    while(i+1<n && a[i] == a[i+1]) i++;

    if(i+1 < n && a[i]<a[i+1]){
      while(i+1<n && a[i]<=a[i+1]) i++;
    }

    else if(i+1<n && a[i]>a[i+1]){
      while(i+1<n && a[i]>=a[i+1]) i++;
    }
    ans++;
  }
  cout << ans << endl;
}
