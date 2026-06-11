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
     int a,b;
     cin >> a >> b;
     if(a==b)cout << "Draw";
     else if(a==1 || b==1){
        if(a==1)cout << "Alice";
        else cout << "Bob";
     }
     else{
        if(a>b)cout << "Alice";
        else cout << "Bob";
     }
  }


  int main(){
    IOS
       solve();
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
