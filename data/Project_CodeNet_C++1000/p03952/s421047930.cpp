#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define ll long long
#define rep(i,n) for (int i = 0; i < n; i++)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define MOD (1000000007)
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int, int>
#define pli pair<ll, int>a
#define pb push_back

#define mp make_pair
#define all(a) (a).begin(),(a).end()


int main(){
  int n,x; cin >> n >> x;
  if(x == 1 || x == 2*n-1){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  if(n == 2){
    rep(i,3) cout << i+1 << endl;
    return 0;
  }

  vi ans(2*n-1,-1);
  vector<bool> used(2*n,false);
  if(x > 2){
    ans[n-2] = 1;
    used[1] = true;
    ans[n-1] = x;
    used[x] = true;
    ans[n] = x+1;
    used[x+1] = true;
    ans[n+1] = 2;
    used[2] = true;
  }
  else{
    ans[n-2] = x+2;
    used[x+2] = true;
    ans[n-1] = x;
    used[x] = true;
    ans[n] = x-1;
    used[x-1] = true;
    ans[n+1] = x+1;
    used[x+1] = true;
  }

  int num = 1;
  rep(i,2*n-1) {
    if(ans[i] != -1) continue;
    while(used[num]) num++;
    ans[i] = num;
    used[num] = true;
  }

  rep(i,2*n-1) cout << ans[i] << endl;

}