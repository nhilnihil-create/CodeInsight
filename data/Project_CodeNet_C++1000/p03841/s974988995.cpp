#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma comment(linker, "/STACK:2000000")

#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
// #define endl '\n'
using ll = long long;
#define int ll
using db = long double;
using ii = pair<int, int>;

const int N = 2e5 + 5, LG = 19, MOD = 1e9+7;
const int SQ =320;
const long double EPS = 1e-7;
int cntExtra[505];
int cntNeed[505];
int n;
ii x[505];
int take[505*505];
int32_t main(){
#ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
  cin >> n;
  f(i,1,n+1){
    cin >> x[i].F;  x[i].S=i;
    take[x[i].F]=i;
    cntNeed[i]=i-1;
  }

  sort(x+1,x+n+1);
  vector<int> v;
  for(int j = 1; j <= n * n; j++){
    if(!take[j]){
      bool f = false;
      f(i,1,n+1){
        if(cntNeed[x[i].S]){
          cntNeed[x[i].S]--;
          v.push_back(x[i].S);
          f=true;
          break;
        }
      }
      if(!f){
        for(int j = 1; j <= n; j++)
        if(cntExtra[j]){
          f=true;
          v.push_back(j);
          cntExtra[j]--;
          break;
        }
        if(!f){
          cout << "No\n"; return 0;
        }
      }

    } else {
      if(cntNeed[take[j]]){
        cout << "No\n"; return 0;
      }
      v.push_back(take[j]);
      cntExtra[take[j]] += n - take[j];
    }
  }
  cout << "Yes\n";
  for(auto x:v)cout << x << ' ';

  return 0;
}
