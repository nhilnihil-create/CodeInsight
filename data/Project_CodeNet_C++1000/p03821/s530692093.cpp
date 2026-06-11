#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int>a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];


  ll cnt = 0;
  ll tot = 0;
  for(int i = n-1; i >= 0; i--){
    ll na  = a[i]+tot;
    if(na%b[i] == 0) continue;
    else{
      ll m = na/b[i];
      tot += b[i]*(m+1)-na;
    }
    //cout << tot << endl;
  }
  cout << tot << endl;
}
