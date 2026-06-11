#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());

typedef long long ll;

int main(){
  vector<int> a(3);
  rep(i,3) cin >> a[i];
  sort(a);
  cout << a[0]+a[1] << endl;
}