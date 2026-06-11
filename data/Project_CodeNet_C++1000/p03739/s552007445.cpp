#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vst = vector<st>;
using vchar = vector<char>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

int main(){
  ll n;
  cin >> n;
  vll a(n);
  vin(a);
  
  vll a1 = a, a2 = a;
  ll ans1 = 0, ans2 = 0;
  ll pointer = 0;
  ll sum = 0;
  while(pointer < n){
    sum += a1.at(pointer);
    if(pointer % 2 == 0){
      if(sum > 0) pointer++;
      else{
        ans1 += -1 * sum + 1;
        a1.at(pointer) += -1 * sum + 1;        
        sum += -1 * sum + 1; 
        pointer++;
      }
    }
    else{
      if(sum < 0) pointer++;
      else{
        ans1 +=  sum + 1;
        a1.at(pointer) -=  sum + 1;
        sum -= sum + 1; 
        pointer++;
      }
    }
  }
  
  pointer = 0, sum = 0;
  while(pointer < n){
    sum += a2.at(pointer);
    if(pointer % 2 == 1){
      if(sum > 0) pointer++;
      else{
        ans2 += -1 * sum + 1;
        a2.at(pointer) += -1 * sum + 1;
        sum += -1 * sum + 1; 
        pointer++;
      }
    }
    else{
      if(sum < 0) pointer++;
      else{
        ans2 +=  sum + 1;
        a2.at(pointer) -=  sum + 1;
        sum -= sum + 1; 
        pointer++;
      }
    }
  }
cout << min(ans1, ans2) << endl;
}