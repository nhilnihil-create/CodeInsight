#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

ll tableF[200010];
ll tableI[200010];

ll modfact(ll a,ll m){
   if(tableF[a] != -1){
      return tableF[a];
   }
   if(a == 1){
      tableF[a] = 1;
      return tableF[a];
   }
   ll res = 1;
   res = a * modfact(a-1,m);
   res %= m;
   tableF[a] = res;
   return res;
}

ll modpow(ll a,ll n,ll m){//modpow(a,n,m) := a ^ n (mod m)
  ll res = 1;
  while(n > 0){
    if(n & 1)res = res * a % m;
    a = a * a % m;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a,ll p){//modinv(a,p) := pを法とするaの逆元(※pは素数でなければならない)
    ll res = modpow(a,p-2,p);
    return res;
}

ll modCON(ll n,ll r,ll m){
   if(n < 200010){
   ll res = 1;
   if(n == 0 || r == 0){
      return 1;
   }
   res *= tableF[n];
   res %= m;
   res *= tableI[r];
   res %= m;
   res *= tableI[n-r];
   res %= m;
   return res;
   }else{
   ll res = 1;//tableを持ってないときよう
   for(int i = 1;i <= n;i++){
      res *= i;
      res %= m;
   }
   for(int i = 1;i <= r;i++){
      res *= modinv(i,m);
      res %= m;
   }
   for(int i = 1;i <= n-r;i++){
      res *= modinv(i,m);
      res %= m;
   }
   return res;
   }
}

void modfill(ll m){//忘れない　約300ms
   fill(tableF,tableF+200010,-1);
   fill(tableI,tableI+200010,-1);
   tableF[0] = 1;
   tableI[0] = 1;
   for(int i = 1;i < 200010;i++){
      tableF[i] = modfact(i,m);
      tableI[i] = modinv(tableF[i],m);
   }
}


int main(){
  string S;cin >> S;
  int N = S.size();
  int ans = 0;
  int p = 0,g = 0;
  for(int i = 0;i < N;i++){
    if(S[i] == 'g'){
      if(g > p){
        p++;
        ans++;
      }else{
        g++;
      }
    }else{
      if(g > p){
        p++;
      }else{
        g++;
        ans--;
      }
    }
  }
  cout << ans << endl;
}
