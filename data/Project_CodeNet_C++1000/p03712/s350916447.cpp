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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int H, W;
  cin>>H>>W;
  vector<string> arr(H);
  for(int i=0;i<H;++i) cin>>arr[i];
  for(int i=0;i<W+2;++i) cout<<"#";
  cout<<endl;
  for(int i=0;i<H;++i) {
    cout<<"#";
    cout<<arr[i];
    cout<<"#"<<endl;
  }
  for(int i=0;i<W+2;++i) cout<<"#";
  cout<<endl;
}

