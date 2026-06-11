#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int k,t;
  cin >> k >> t;
  vector<int> a(t);
  rep(i,t) cin >> a[i];
  sort(a.rbegin(),a.rend());
  int rest = k - a[0];
  cout << max(a[0] - rest - 1,0) << endl;
  
  
  return 0;
    

}
