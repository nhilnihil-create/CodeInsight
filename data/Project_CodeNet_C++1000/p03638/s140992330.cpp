#include <bits/stdc++.h>
#include <cstdint>
#define pi 3.14159
#define ll long long
// #define int ll
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
#define mod 1000000007
#define f first
#define s second
#define pii pair< int, int >
#define vi vector<int>
#define vpii vector<pii>
#define debug(v) for(auto i:v) cout<<i<<" ";
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define sz(a) a.size()
#define tc int t; cin >> t; while(t--)

using namespace std;
string repeat(string s, int n) {
    string s1 = "";
    for (int i=0; i<n;i++)
        s1+=s;
    return s1;
}
string getString(char x) {
    string s(1, x);
    return s;
}

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b){
    if (a == 0)  return b;
    return gcd(b % a, a);
}
void  solve(){
  int h,w;
  cin>>h>>w;
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  vector<vector<int>> dp(h,vi(w,0));
  int idx=0;
  rep(i,0,h){
    if(i%2==0){
      rep(j,0,w){
        if(a[idx]) a[idx]-=1,dp[i][j]=idx+1;
        else {
          idx=idx+1;
          a[idx]-=1,dp[i][j]=idx+1;
        }
      }
    }
    else{
      rrep(j,w-1,0){
        if(a[idx]) a[idx]-=1,dp[i][j]=idx+1;
        else {
          idx=idx+1;
          a[idx]-=1,dp[i][j]=idx+1;
        }
      }
    }
  }
  rep(i,0,h){
    rep(j,0,w) cout<<dp[i][j]<<" ";
    cout<<endl;
  }
}
int main(){
    optimizeIO();
    solve();
}
