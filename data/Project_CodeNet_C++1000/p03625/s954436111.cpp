#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>
#include <map>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
//priority_queue<llint> q;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

llint n;

void solve(){
  cin >> n;
  vector<llint> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  llint m1=0,m2=0;
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  llint tmp=0;
  for(int i=0;i<n;i++){
    if(a[i]==tmp){
      if(m1!=0){
        m2=a[i];
        break;
      }
      else{
        m1=a[i];
        tmp=0;
        continue;
      }
    }
    tmp=a[i];
  }
  cout << m2*m1 << endl;
}

int main() {
  solve();
  return 0;
}
