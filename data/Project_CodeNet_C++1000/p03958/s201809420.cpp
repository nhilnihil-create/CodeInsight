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
  int k,t;
  cin >> k >> t;
  int MA = 0;
  rep(i,t){
    int a;
    cin >> a;
    MA = max(MA,a);
  }
  if((MA - 1) > (k-MA)){
    cout << (MA-1) - (k-MA) << endl;
  }
  else{
    cout << 0 << endl;
  }
}