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
     int n;
     cin >> n;
     vector<int> v(n);
     for(int i=0;i<n;i++)cin >> v[i];
     int i=0;
     for(i=n-1;i>=0;i-=2){
        cout << v[i] <<' ';
        // assert((i<n && i>=0));
     }
     for(int j=i+1;j<n;j+=2){
       if(j<n && j>=0)
       cout << v[j] << ' ';

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
