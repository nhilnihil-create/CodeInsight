#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int mod = 1000000007;

int main() {
 // freopen("in.cpp","r",stdin);
  int n;
  ll ret=1;
  int pre=-1,s=0;
  cin>>n;
  for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    if(pre+2<=x){
      ret=ret*(s+1)%mod;
      s++;
      pre+=2;
    } else {
      ret=ret*(s+1)%mod;
    }
  }
  cout<<ret<<endl;
  return 0;
}
