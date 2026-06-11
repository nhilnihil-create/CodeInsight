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
  int n;
  cin >> n;
  vint A(n);
  int m;
  cin >> m;
  rep(i,2*m){
    int a;
    cin >> a;
    a--;
    A[a]++;
  }
  bool flag = true;
  rep(i,n){
    if(A[i] % 2 == 1) flag = false; 
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}