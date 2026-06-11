#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <complex>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  ll k,n;
  ll ans[100] = {};
  cin >> k;
  n = 50;

  for(int i=0;i<n;i++){
    ll p;
    if(i < k%n){
      p = k/n + 1;
    }else{
      p = k/n;
    }
    
    ans[i] = (n-1) + n * p - (k - p);
  }

  printf("%lld\n",n);
  for(int i=0;i<n;i++){
    printf("%lld%c",ans[i]," \n"[i ==n-1]);
  }
  
  return 0;
}
