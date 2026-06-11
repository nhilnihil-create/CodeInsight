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
     int h,w;
     cin >> h >> w;
     int n;
     cin >> n;
     vector<int> v(n);
     for(int i=0;i<n;i++)cin >> v[i];
     vector<vector<int>> grid(h,vector<int> (w));
     int a = 0;
     int k = v[a];
     for(int i=0;i<h;i++){
       for(int j=0;j<w;j++){
          if(k>0)grid[i][j]=a+1,k--;
          else{
            a++;
            grid[i][j]=a+1;
            k = v[a]-1;
          }
          // cout << grid[i][j] << ' ';
       }
       // cout << '\n';
     }
     for(int i=0;i<h-1;i++){
        if(grid[i][w-1]==grid[i+1][0])reverse(all(grid[i+1]));
     }
     for(auto row:grid){
       for(int x:row)
       cout << x << ' ';
       cout << '\n';
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
