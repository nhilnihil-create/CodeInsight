#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll K, S;
    cin >> K >> S;
    ll cnt = 0;
    for(int X=0; X<=K; ++X){
      for (int Y = 0; Y<=K; Y++){
          ll Z = S - X - Y;
          if (Z >= 0 && Z <= K) cnt++;
      }
    }
    cout << cnt << endl;
    return 0;
}