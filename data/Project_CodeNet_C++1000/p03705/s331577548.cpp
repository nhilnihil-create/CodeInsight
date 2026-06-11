#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int> 

int main(){
  ll N, A, B; cin >> N >> A >> B;
  ll ans;
  if (N==1){
    if (A==B) ans = 1;
    else ans = 0;
  }
  else {
    if (A>B) ans = 0;
    else ans = (N-2)*(B-A)+1;
  }

  cout << ans << endl;
  return 0;
}