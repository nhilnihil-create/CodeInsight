#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; ++i)
using ll = long long;
const ll MOD = 1000000007;//998244353;
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n; cin >> n;
   vector<int> a(n);
   rep(i,n)cin>>a[i];
   sort(a.begin(),a.end());reverse(a.begin(),a.end());
   a.push_back(0);
   int k=1;
   while(k<a[k])k++;
   int x = 0, y = a[k-1]-k;
   while(a[k+x]==k)x++;
   if ((x%2==0)&&(y%2==0))cout << "Second" << endl;
   else cout << "First" << endl; 
}