#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string O, E;
  cin>>O>>E;
  string ans;
  for(int i=0;i<O.size()+E.size();++i) {
    if(i%2==0) ans += O[i/2];
    else ans += E[(i-1)/2];
  }
  cout<<ans<<endl;
}
