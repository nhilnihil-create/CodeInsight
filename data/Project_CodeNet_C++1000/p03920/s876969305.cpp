#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#define REP(i,n) for(int i = 0;i < (n);i++)
#define pb push_back
using namespace std;
const int INF = 1e9;
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  bool f[n];
  REP(i,n){
    f[i] = false;
  }
  ll sum = 0;
  for(int i = 0;i < n;i++){
    if(sum+i+1 <= n){
      sum += i+1;
      f[i] = true;
    }
    else{
      f[i] = true;
      f[sum+i+1-n-1] = false;
      break;
    }
    //cout << sum << endl;
  }
  REP(i,n){
    if(f[i])
      cout << i+1 << endl;
  }
  return 0;
}
