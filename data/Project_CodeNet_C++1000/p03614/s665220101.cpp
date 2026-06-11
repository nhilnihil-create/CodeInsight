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
  vector<int> a(n);
  rep(i, n){
    cin>>a[i];a[i]--;
  }
  int ans=0;
  rep(i, n-1){
    if(a[i]==i){
      swap(a[i], a[i+1]);
      ans++;
    }
  }
  if(a[n-1]==n-1)ans++;
  cout<<ans<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
