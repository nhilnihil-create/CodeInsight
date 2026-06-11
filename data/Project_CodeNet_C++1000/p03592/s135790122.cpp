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
#define vll vector<ll>
#define vbool vector<bool>
#define INF 1000000009
using P = pair<int,int>;
 
int main() {
  #define int long long
  int n,m,k;
  cin >> n >> m >> k;
  bool flag = false;
  erep(i,n) erep(j,m){
    int ans = i*(m-j) + j*(n-i);
    if(ans == k){
      flag = true;
      break;
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;
} 