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
  int n, t;cin>>n>>t;
  vector<int> a(n);
  rep(i, n){
    cin>>a[i];
  }
  vector<int> m(n);
  m[0]=a[0];
  rep(i, n-1){
    m[i+1]=min(m[i], a[i+1]);
  }
  int cnt=0, Md=-1;;
  rep(i, n){
    Md=max(Md, a[i]-m[i]);
  }
  rep(i, n){
    if(a[i]-m[i]==Md)cnt++;
  }
  cout<<cnt<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
