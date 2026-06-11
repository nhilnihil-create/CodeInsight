#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}
int gyaku(int n){
    return modpow(n,MOD-2);
}
signed main() {
  string s;
  cin>>s;
  int n;
  n=s.size();
  int i=0;
  vector<string>v={"dreamer","dream","erase","eraser"};
  while(true){
    if(i==n){cout<<"YES";break;}
    if(i>n-5){cout<<"NO";break;}
    if(s.substr(n-i-5,5)==v[1]||s.substr(n-i-5,5)==v[2]){
      i+=5;
      continue;
    }
    if(i>n-6){cout<<"NO";break;}
    if(s.substr(n-i-6,6)==v[3]){
      i+=6;
      continue;
    }
    if(i>n-7){cout<<"NO";break;}
    if(s.substr(n-i-7,7)==v[0]){
      i+=7;
      continue;
    }
    cout<<"NO";
    break;
  }
}
