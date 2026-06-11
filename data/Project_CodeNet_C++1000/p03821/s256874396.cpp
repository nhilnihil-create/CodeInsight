#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
ll cnt = 0;

int main(){
  int n;    cin >> n;
  vector<ll>a(n),b(n);
  for(int i=0;i<n;i++){
     cin >> a.at(i) >> b.at(i);
  }
  for(int i=n-1;i>=0;i--){
      a[i]+=cnt;
      if(a[i] % b[i] != 0){
          ll m;
          m=a[i] / b[i];
          cnt+=(m+1)*b[i]-a[i];
      }
  }
  cout << cnt << endl;
}