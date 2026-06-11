#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;

int main(){
  ll N, K;
  cin >> N >> K;
  vll a(N), aa(N);
  vll highest(N), highestt(N);
  for(int i = 0; i < N; i++){
    cin >> a.at(i);
    if(i == 0) highest.at(0) = a.at(0);
    else if(a.at(i) > highest.at(i-1)) highest.at(i) = a.at(i);
    else highest.at(i) = highest.at(i-1);
  }
  aa = a; highestt = highest;


  ll result = INF;
  for(int tmp = 0; tmp < (1 << (N-1)); tmp++){
    bitset<14> bit(tmp);
    if(bit.count() !=  K-1) continue;
    a = aa; highest = highestt;
    ll sum = 0;
    for(int i = 0; i < N-1; i++){
      if(bit.test(i)){ //i+1番目がみえる
        if(a.at(i+1) <= highest.at(i)){
          sum += (highest.at(i) + 1LL - a.at(i+1));
          a.at(i+1) = highest.at(i) + 1LL;
        }
      }
      highest.at(i+1) = max(a.at(i+1), highest.at(i));  // ハマった原因は、見えるようにしたいビルでしかhighestを更新していなかったこと。見えるようにしたいビル以外もhighestを更新していることがある。
    }
    chmin(result, sum);
  }
  cout << result << endl;
}
