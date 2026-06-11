#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
  int n;
  cin >> n;
  vector<int> a(n),b(n,0),d(n,0);
  vector<vector<int>> c(n,vector<int>(0));
  rep(i,n-1){
    cin >> a[i+1];
    a[i+1]--;
    b[a[i+1]]++;
  }
  queue<int> q;
  rep(i,n){
    if (b[i]==0) q.push(i);
  }
  while(!q.empty()){
    int f=q.front();
    q.pop();
    sort(all(c[f]));
    reverse(all(c[f]));
    rep(i,c[f].size()){
      d[f]=max(d[f],c[f][i]+i+1);
    }
    if (f==0) break;
    c[a[f]].push_back(d[f]);
    b[a[f]]--;
    // cout << f << " " << d[f] << endl;
    if (b[a[f]]==0) q.push(a[f]);
  }
  cout << d[0] << endl;
}
