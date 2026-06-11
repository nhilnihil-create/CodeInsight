#include <iostream>
  #include <complex>
  #include <vector>
  #include <string>
  #include <algorithm>
  #include <cstdio>
  #include <numeric>
  #include <cstring>
  #include <ctime>
  #include <cstdlib>
  #include <set>
  #include <map>
  #include <unordered_map>
  #include <unordered_set>
  #include <list>
  #include <cmath>
  #include <bitset>
  #include <cassert>
  #include <queue>
  #include <stack>
  #include <deque>
 #include <iomanip>
#include <fstream>
#include <climits>
 
  using namespace std;
   
 
//abcdefghijklmnopqrstuvwxyz
//ABCDEFGHIJKLMNOPQRSTUVWXYZ

  typedef long long ll;
  typedef long double lld;
  typedef unsigned long long ull;
  int INF = INT_MAX;
  ll mod = 1e9+7;
  // lld PI = 3.141592653;



  int main()
  {
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     
    int n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    for (int i = 0;i<n;i++) cin>>a[i].first >> a[i].second;
    ll ans = 0;
    for (int i = n-1; i>=0; i--){
      a[i].first += ans;
      ll need = (a[i].second - a[i].first % a[i].second) % a[i].second;
      ans += need;
    }
    cout<<ans<<"\n";







}
  