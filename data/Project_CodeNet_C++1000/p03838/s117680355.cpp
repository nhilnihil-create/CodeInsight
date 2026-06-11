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
#define INF 100000000


int main(){
  ll x,y;
  cin >> x >> y;
  if(x < 0){
    if(abs(x) < abs(y)){
      if(y >= 0) cout << abs(x + y) + 1 << endl;
      else cout << abs(x - y) + 2 << endl;
    }
    else{
      if(y <= 0) cout << abs(y - x) << endl;
      else cout << abs(x + y) + 1 << endl;
    }
  }
  else{
    if(abs(x) > abs(y)){
      if(y <= 0) cout << abs(x + y) + 1 << endl;
      else cout << abs(x - y) + 2 << endl;
    }
    else{
      if(y >= 0) cout << abs(y - x) << endl;
      else cout << abs(x + y) + 1 << endl;
    }
  }
}


