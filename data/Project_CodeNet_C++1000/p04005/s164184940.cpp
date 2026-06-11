#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
#define len(x) (ll)(x).length()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  vector<ll> a(3);
  cin>>a[0]>>a[1]>>a[2];
  sort(all(a));
  if(a[0]%2==1&&a[1]%2==1&&a[2]%2==1){
    cout<<a[0]*a[1]<<endl;
  }else{
    cout<<0<<endl;
  }
}