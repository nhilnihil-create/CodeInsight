#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<numeric>
#include<limits>
#include<bitset>
#include<functional>
#include<type_traits>
#include<queue>
#include<stack>
#include<array>
#include<random>
#include<utility>
#include<cstdlib>
#include<ctime>
#include <numeric>
#include <stdio.h>
#include<cassert>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
 int main() {
   int n, k;
   cin >> n >> k;
   ll a[n];
   for (int i=0;i<n;i++) {
     cin >> a[i];
   }
   const ll INF = 1e18;
   ll res = INF;
   for(int bit=0; bit<(1<<n);bit++) {
     ll cost =0;
     ll mh = 0;
     int count = 0;
     for(int i=0; i<n;i++) {
       if((bit >> i) &1) {
         cost += max(0LL, mh-a[i] +1);
         mh = max(mh+1, a[i]);
         count++;
       } else if (mh < a[i]) {
         mh = a[i];
         count++;
       }
     }
     if(count >= k) res = min(res, cost);
   }
   cout << res << endl;
   return 0;
 }