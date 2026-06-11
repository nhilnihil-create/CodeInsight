#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll N,A,B;
  cin >> N >> A >> B;
  if(A>B||(N==1&&A!=B)){
    cout << 0 << endl;
  }else{
    cout << ((N-1)*B+A)-((N-1)*A+B)+1 << endl;
  }
}
      