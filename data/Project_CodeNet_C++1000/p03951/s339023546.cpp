#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  for(int i=n; i>=0; i--){
    bool same = true;
    for(int j=0; j<i; j++){
      if(s[n-i+j] != t[j]) same = false;
    }
    if(same){
      cout << n+n-i << endl;
      return 0;
    }
  }
}