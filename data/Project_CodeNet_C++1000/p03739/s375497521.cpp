#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i ,n){
    cin >> a[i];
  }
  rep(i, n-1){
    a[i+1]+=a[i];
  }
  ll now=0, num=0;
  rep(i, n){
    if(i%2==0 && a[i]+now<=0){
      num+=1-(a[i]+now);
      now+=1-(a[i]+now);
    }
    if(i%2==1 && a[i]+now>=0){
      num+=(a[i]+now)+1;
      now-=(a[i]+now)+1;
    }
  }
  ll now2=0, num2=0;
  rep(i, n){
    if(i%2==1 && a[i]+now2<=0){
      num2+=1-(a[i]+now2);
      now2+=1-(a[i]+now2);
    }
    if(i%2==0 && a[i]+now2>=0){
      num2+=(a[i]+now2)+1;
      now2-=(a[i]+now2)+1;
    }
  }
  ll ans=min(num, num2);
  cout << ans << endl;
  return 0;
}
