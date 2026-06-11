#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>

using namespace std;

typedef long long ll;

typedef std::pair<int, int> ipair;
bool lessPair(const ipair& l, const ipair& r){return l.second < r.second;}
bool morePair(const ipair& l, const ipair& r){return l.second > r.second;}

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll MOD = 1e9 + 7;
// const long long INF = 1LL<<60;
void add(long long &a, long long b) { a += b; if (a >= MOD) a -= MOD; }
void sub(long long &a, long long b) { a -= b; if (a < 0) a += MOD; }
void mul(long long &a, long long b) { a *= b; a %= MOD; }
ll llmin(ll a, ll b) { if (a < b) return a; else return b; }
ll llmax(ll a, ll b) { if (a < b) return b; else return a; }
ll llabs(ll a) { if (a >= 0) return a; else return - a; }
ll llmodpow(ll a, ll n) {
   if (n == 0) return 1;
   ll tmp = llmodpow(a, n / 2);
   mul(tmp, tmp);
   if (n & 1) mul(tmp, a);
   return tmp;
}

int main() {
   int N;
   cin >> N;
   string S1, S2;
   cin >> S1;
   cin >> S2;
   bool flg[N][2];
   memset(flg, false, sizeof(flg));
   ll ans = 1;
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < 2; j++) {
         if (flg[i][j]) continue;
         if (j == 0) {
            if (S1[i] == S2[i]) {
               if (i == 0) mul(ans, 3);
               else if (S1[i - 1] == S2[i - 1]) mul(ans, 2);
               else mul(ans, 1);
               flg[i][j] = true;
               flg[i][j + 1] = true;
            } else {
               if (i == 0) mul(ans, 6);
               else if (S1[i - 1] == S2[i - 1]) mul(ans, 2);
               else mul(ans, 3);
               flg[i][j] = true;
               flg[i + 1][j] = true;
               flg[i][j + 1] = true;
               flg[i + 1][j + 1] = true;
            }
         } else {
            if (i == 0) mul(ans, 2);
            else if (S1[i] == S2[i - 1]) mul(ans, 2);
            else mul(ans, 1);
            flg[i][j] = true;
            flg[i + 1][j] = true;
         }
      }
   }
   cout << ans << endl;
   return 0;
}
