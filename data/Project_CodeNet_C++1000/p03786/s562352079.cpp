#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(),a.end());
  ll size=a[0];
  int ans=n;
  for(int i=1;i<n;i++){
    if(size*2<a[i]){
      ans=n-i;
    }
    size+=a[i];
  }
  cout << ans;
  return 0;
}