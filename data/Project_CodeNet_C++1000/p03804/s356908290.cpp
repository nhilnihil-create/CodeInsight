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
     int n,m;
     cin >> n >> m;
     vector<string> v(n);
     vector<string> v1(m);
     for(int i=0;i<n;i++)cin >> v[i];
     for(int j=0;j<m;j++)cin >> v1[j];
     for(int i=0;i+m-1<n;i++){
       for(int j=0;j+m-1<n;j++){
         bool ok = true;
          for(int k=0;k<m;k++){
             for(int h=0;h<m;h++){
                 if(v[i+k][j+h]!=v1[k][h]){ok=false;break;}
             }
             if(!ok)break;
          }
          if(ok){cout << "Yes";return;}
       }
     }
     cout << "No";
  }


  int main(){
    IOS
       solve();
  }
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
// don't assign after modifying
