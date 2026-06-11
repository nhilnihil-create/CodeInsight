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
  int N, x;
  cin>>N>>x;
  if(N==2) {
    if(x==2) {
      cout<<"Yes"<<endl;
      cout<<1<<endl;
      cout<<2<<endl;
      cout<<3<<endl;
    }
    else {
      cout<<"No"<<endl;
    }
    return 0;
  }
  if(x-2>=1 && x+1<=2*N-1) {
    cout<<"Yes"<<endl;
    vector<ll> arr(2*N-1);
    for(int i=0;i<2*N-1;++i) arr[i] = -1;
    arr[N-2] = x-1;
    arr[N-1] = x;
    arr[N] = x+1;
    arr[N+1] = x-2;
    vector<ll> arr1;
    for(int i=1;i<=2*N-1;++i) {
      if(x-2<=i && i<=x+1) continue;
      arr1.push_back(i);
    }
    int index = 0;
    for(int i=0;i<2*N-1;++i) {
      if(arr[i]==-1) {
        arr[i] = arr1[index];
        index++;
      }
    }
    for(int i=0;i<2*N-1;++i) cout<<arr[i]<<endl;
  }
  else if(x-1>=1 && x+2<=2*N-1) {
    cout<<"Yes"<<endl;
    vector<ll> arr(2*N-1);
    for(int i=0;i<2*N-1;++i) arr[i] = -1;
    arr[N-2] = x+2;
    arr[N-1] = x;
    arr[N] = x-1;
    arr[N+1] = x+1;
    vector<ll> arr1;
    for(int i=1;i<=2*N-1;++i) {
      if(x-1<=i && i<=x+2) continue;
      arr1.push_back(i);
    }
    int index = 0;
    for(int i=0;i<2*N-1;++i) {
      if(arr[i]==-1) {
        arr[i] = arr1[index];
        index++;
      }
    }
    for(int i=0;i<2*N-1;++i) cout<<arr[i]<<endl;
  }
  else cout<<"No"<<endl;
}

