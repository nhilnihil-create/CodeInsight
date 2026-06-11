  #include <bits/stdc++.h>
  using namespace std;

  #define vi vector<int>
  #define all(v) v.begin(),v.end()
  #define ll long long int
  #define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  #define D1(x) {cerr<<" [" <<#x<<": "<<x<<"]";cout << endl;}
  #define D2(x) {cerr<<" [" <<#x<<": ";for(auto it:x)cerr<<it<< " ";cerr<<"] ";cout << endl;}

  const ll MOD=1e9+7;

  void solve(){
     ll n,m;
     cin >> n >> m;
     if(n<m)swap(n,m);
     if(n > m+1)cout << 0;
     else{
        if(n==m+1){
          ll prod=1;
          for(ll i=1;i<=n;i++){
             prod = (prod%MOD*i%MOD)%MOD;
          }
          for(ll i=1;i<=m;i++){
             prod = (prod%MOD*i%MOD)%MOD;
          }
          cout << prod;
        }
        else{
          ll prod=2;
          for(ll i=1;i<=n;i++){
             prod = (prod%MOD*i%MOD)%MOD;
          }
          for(ll i=1;i<=m;i++){
             prod = (prod%MOD*i%MOD)%MOD;
          }
          cout << prod;
        }
     }
  }


  int main(){
    IOS
       solve();
       cerr <<endl <<"[ Time : " << (float)clock() / CLOCKS_PER_SEC << " secs ]" << endl;
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
