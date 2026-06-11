#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  map<int,int> mp;
  rep(i,n){
    int x;
    cin >> x;
    mp[x]++;
  }
  int jama = 0;
  for(auto p : mp) jama += max(p.second-1,0);
  cout << mp.size()-jama%2 << endl;
}