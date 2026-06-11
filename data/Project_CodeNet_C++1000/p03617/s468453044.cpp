#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
#define all(v) v.begin(), v.end()

int main(){
  ll Q,H,S,D,N;
  cin >> Q>>H>>S>>D>>N;
  if(N%2==0){
    cout << (N/2)*min(min(8*Q,4*H),min(2*S,D)) << endl;
  }else{
    cout << (N/2)*min(min(8*Q,4*H),min(2*S,D))+min(min(4*Q,2*H),S) << endl;
  }
       
    
  

}