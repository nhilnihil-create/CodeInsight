#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  string a,b,c; cin>>a>>b>>c;
  if(a[a.size()-1] == b[0] && b[b.size()-1] == c[0]){
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
  
}