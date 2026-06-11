#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
using namespace std; typedef long long ll; const int INF=100; typedef pair<int,int> P;
const int ld=10;

int main() {
  int n; cin>>n;
  int a[n]; for(int i=0;i<n;i++) cin>>a[i];
  int mx=0,mn=n;
  for(int i=0;i<n;i++) mx=max(mx,a[i]), mn=min(mn,a[i]);

  if (mx-mn >= 2) {
    cout<<"No"<<endl; return 0;
  } else if (mx-mn == 0) {
    if (a[0]==n-1 || n/2 >= a[0]) {
      cout<<"Yes"<<endl; return 0;
    } else {
      cout<<"No"<<endl; return 0;
    }
  } else if (mx-mn == 1) {
    int mxx=0;
    for(int i=0;i<n;i++) {
      if (a[i]==mx) mxx++;
    }
    if (mxx == 1) {
      cout<<"No"<<endl; return 0;
    }
    if ((n-mxx) <= mn && mx <= (n-mxx) + (mxx/2)) {
      cout<<"Yes"<<endl; return 0;
    } else {
      cout<<"No"<<endl; return 0;
    }
  }
}