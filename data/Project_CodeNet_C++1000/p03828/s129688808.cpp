#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stdio.h>
#include <list>
#include <numeric>
#include <stack>
#include <queue>
#include <tuple>
#include <bitset>
#include <map>
#include <math.h>
//　ceil(a/b)   (a + (b - 1))/ b
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int,int> P;
const int inf=1000000007;
const ll mod=1000000007;
const double PI=3.14159265358979323846;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

ll gcd(ll a, ll b){
  if (b==0) return a;
  else return gcd(b,a%b);
}

int cans(bool f){
  if(f) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


char isused[100010];


bool isPrime(int N){
  for(int i=2; i*i<=N; i++){
    if(N%i == 0) return false; 
  }
  return true;
}

int main(){
  int N;
  cin >> N;

  ll ans = 1;
  for(int i = 2; i<=N; i++){
    ll cnt = 0;
    ll div = i;
    if(isPrime(div)){
      while(N/div){
      cnt += N/div;
      div *= i;
      }
      // cout << i << ":" << cnt << endl;
      ans *= cnt+1;
      ans %= mod;
    }
  }
   
  cout << ans%mod << endl;
  
  return 0;
}

