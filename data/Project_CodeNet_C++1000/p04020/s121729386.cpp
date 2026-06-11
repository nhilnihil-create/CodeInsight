/*

*/
#include<iostream>
#include<iomanip>
#include<ios>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)
#define MAX_N 10000

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;
const ll MOD = ll(1e9+7);

int main(){
  int n;cin>>n;
  ll ans=0LL;
  int res=0;
  rep(i, n){
    int a;cin>>a;
    if(res==1 && a>0){
      a--;ans+=a/2+1;
      res=a%2;
    }else if(res==0 && a>0){
      ans+=a/2;
      res=a%2;
    }else{
      res=0;
    }
  }
  cout<<ans<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
