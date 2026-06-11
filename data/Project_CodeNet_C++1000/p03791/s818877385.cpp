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

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;


#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 100010


int main(){
  int n;
  int x[SIZE];

  scanf("%d",&n);

  for(int i=0;i<n;i++){
    scanf("%d",x+i);
  }


  ll ans = 1;
  int t = 1,s = 0;
  
  vector<int> vec;
  
  for(int i=0;i<n;i++){
    if(x[i] >= t){
      x[i] = t;
    }else{
      t = x[i];
    }
        
    if(x[i-1]+1 != x[i]){
      s = 0;
    }
    s ++;

    if(s%2 == 0){
      vec.push_back(i+1);
      t += 1;
    }else{
      t += 2;
    }
  }
  
  for(int i=0;i<n;i++){
    if(i < vec.size())
      ans = (ans*(vec[i]-i))%mod;
    else
      ans = (ans * (n - i))%mod;
  }

  printf("%lld\n",ans);
  
  return 0;
}
