#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  string s;
  int k;
  cin >> s >> k;
  int len = s.size();
  vint A(len);
  rep(i,len){
    if(s[i] != 'a'){
      A[i] = 'z' - s[i] + 1;
    }
  }
  rep(i,len){
    if(k >= A[i]){
      k -= A[i];
      A[i] = 0;
    }
  }
  if(k > 0){
    if(A[len-1] > k) A[len-1] = (A[len-1] - k)%26;
    else A[len-1] = 26 - (k%26);
  }
  rep(i,len){
    if(A[i] == 0) cout << 'a';
    else cout << (char)('z'-A[i]+1);
  }
  cout << endl;
}