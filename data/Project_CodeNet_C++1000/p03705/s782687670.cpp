#include<algorithm>//sort(all(変数),greater<型名>())で降順に、*max_element(all(変数))で最大値を獲得
#include<bits/stdc++.h>
#include<cmath>//切り上げceil(値)
#include<deque>
#include<iomanip>//setprecision(数字)
#include<iostream>
#include<list>
#include<map>
#include<numeric>
// xとyのgcdは__gcd(x,y),xとyのlcmは(x*y)/__gcd、accumulate(all(変数),0)で要素の全加算
#include<queue>//priority_queue<型名> 変数
#include<set>
#include<stack>
#include<string>//変数.substr(どこから,いくつ)
#include<vector>
#define rep(i,n)  for(ll i=0; i<n; i++)
#define rrep(i,n) for(ll i=n-1; 0<=i; i--)
#define vll vector<ll>
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  ll n,a,b; cin >> n >> a >> b;
  if(n == 1){
    if(a == b){
      cout << 1;
    }else{
      cout << 0;
    }
  }else{
    if(a > b){
      cout << 0;
    }else{
      cout << (n-2)*(b-a)+1;
    }
  }
  cout << "\n";
  return 0;
}
