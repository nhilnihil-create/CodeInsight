#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
int n,a[N],x[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
    x[a[i]]++;
    x[a[i]+1]++;
    if(a[i])x[a[i]-1]++;
  }
  cout<<*max_element(x,x+100001);
  return 0;
}