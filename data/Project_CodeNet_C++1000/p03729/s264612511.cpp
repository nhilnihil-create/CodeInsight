#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;



  
int main() {
  string a,b,c;
  cin >>a>>b>>c;
  if(a[a.size()-1]==b[0]&&b[b.size()-1]==c[0]){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}
      
       

