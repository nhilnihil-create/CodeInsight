#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
typedef long double ld;
#define MOD1 1000000007
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j,result=0;
  string s;
  ll yaku[1010]={0};
  cin >> n;
  for(i=2;i<=n;i++){
    //iの素因数分解
    ll tmp=i;
    for(j=2;j<=sqrt(i) && tmp>=2;j++){
      while(tmp%j==0){
        yaku[j]++;
        tmp /= j;
      }
    }
    if(tmp>=2){
      yaku[tmp]++;
      tmp=1;
    }
  }
  result=1;
  for(i=2;i<=n;i++){
    result *= yaku[i]+1;
    result %= MOD1;
  }
  cout << result << endl;
  return 0;
}