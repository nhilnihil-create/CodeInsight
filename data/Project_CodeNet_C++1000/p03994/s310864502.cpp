#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>
#include <map>

typedef long long ll;
#define rep(i, a, n) for(int i = a; i<n; i++)
#define ALL(a) begin(a), end(a)
#define mii map<int, int>
#define msi map<string, int>
#define vi vector<int>
#define vl vector<ll>
#define MOD 1000000007
#define INF 1e9
#define showVector(v) rep(i,0,v.size()){p(v[i]);p(" ")} pl("")
#define p(s) std::cout << s ;
#define pl(s)  std::cout << s << endl;
using namespace std;

// 素数判定 O(√n)
bool is_prime(int n){
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

// 各桁の和を計算する関数
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

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

//想定解答との絶対誤差または相対誤差が 10−6以下の場合+1以上だしておく。適当に15とかでもおｋ．
//cout << fixed << setprecision(15);

int main() {
    string s;
    ll K;
    map<char, int> mp;
    mp['a'] = 0;
    mp['b'] = 25;
    mp['c'] = 24;
    mp['d'] = 23;
    mp['e'] = 22;
    mp['f'] = 21;
    mp['g'] = 20;
    mp['h'] = 19;
    mp['i'] = 18;
    mp['j'] = 17;
    mp['k'] = 16;
    mp['l'] = 15;
    mp['m'] = 14;
    mp['n'] = 13;
    mp['o'] = 12;
    mp['p'] = 11;
    mp['q'] = 10;
    mp['r'] = 9;
    mp['s'] = 8;
    mp['t'] = 7;
    mp['u'] = 6;
    mp['v'] = 5;
    mp['w'] = 4;
    mp['x'] = 3;
    mp['y'] = 2;
    mp['z'] = 1;
    cin >> s >> K;
    rep(i, 0, s.length()) {
        if (K >= mp[s[i]]) {
            K -= mp[s[i]];
            s[i] = 'a';
        }
    }


    while(K>0) {
        if (K > 26) {
            if (s[s.length()-1] == 'a') {
                K -= 26;
            } else {
                K--;
                if (s[s.length()-1] == 'z') {
                    s[s.length()-1] = 'a';
                } else {
                    s[s.length()-1] += 1;
                }
            }
        } else {
            K--;
            if (s[s.length()-1] == 'z') {
                s[s.length()-1] = 'a';
            } else {
                s[s.length()-1] += 1;
            }
        }
    }
    cout << s << endl;
    return 0;
}