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
     string s;
     cin >> s;
     int n =s.size();
     int j = -1;
     int k =0;
     for(int i=0;i<n;i++){
        if(s[i]=='A' && j==-1)j=i+1;
        if(s[i]=='Z')k=i+1;
     }
     // D1(k);D1(j);
     cout << k-j+1;
  }


  int main(){
    IOS
       solve();
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
