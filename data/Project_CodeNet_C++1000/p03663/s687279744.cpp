#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
#include <math.h>
#include <functional>
#include <bitset>

#define repeat(i,n) for (long long i = 0; (i) < (n); ++ (i))
#define debug(x) cerr << #x << ": " << x << '\n'
#define debugArray(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i] << '\n'
#define debugArrayP(x,n) for(long long i = 0; (i) < (n); ++ (i)) cerr << #x << "[" << i << "]: " << x[i].first<< " " << x[i].second << '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> vint;
typedef vector<ll> vll;
const ll INF = LLONG_MAX/10;
const ll MOD = 1e9+7;


int main(){
  ll ans = 0;
  ll pow10 = 1e13;
  ll many9 = pow10-1;
  ll p10=1;
  repeat(i,10){
    ll low=i==0?0:-1,high=10;
    while(high-low>1){
      ll mid = (high+low)/2;
      ll a = ans*10+mid;
      cout << "? "<< a*pow10+many9 << endl;
      char in;
      cin >> in;
      if(in == 'Y'){
        high = mid;
      }else{
        low = mid;
      }
    }
    if(high==0){
      cout << "? "<<ans+1 << endl;
      char in;
      cin >> in;
      if((in == 'Y')^(ans+1==p10)){
        break;
      }
    }
    ans = ans*10+high;
    pow10 /=10;
    many9 /=10;
    p10 *= 10;
  }
  cout << "! " << ans << endl;
  return 0;
}
