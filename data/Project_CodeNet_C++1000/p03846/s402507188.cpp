#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  ll n;
  cin >> n;
  ll ans = 1;
  vll A(n);
  rep(i,n) cin >> A[i];
  sort(A.begin(),A.end());
  bool judge = true;
  if(n % 2 == 0){
    ll key = 1;
    for(int i = 0;i < n-1;i += 2){
      if(A[i] == key && A[i+1] == key){
        key += 2;
        ans *= 2;
        ans %= 1000000007;
      }
      else{
        judge = false;
        break;
      }
    }
  }
  else{
    ll key = 0;
    if(A[0] != 0){
      judge = false;
    }
    else{
      key+= 2;
    }
    for(int i = 1;i < n-1;i += 2){
      if(A[i] == key && A[i+1] == key){
        key += 2;
        ans *= 2;
        ans %= 1000000007;
      }
      else{
        judge = false;
        break;
      }
    }
  }
  if(judge) cout << ans << endl;
  else cout << 0 << endl;
}