#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){
  int k,t;
  cin >> k >> t;
  int mx = 0;
  rep(i,k){
    int a;
    cin >> a;
    mx = max(mx,a);
  }
  cout << max(mx-1-(k-mx),0) << endl;
 
}
