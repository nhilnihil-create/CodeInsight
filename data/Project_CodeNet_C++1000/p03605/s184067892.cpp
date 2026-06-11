        #include <bits/stdc++.h>
        using namespace std;
        #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

     signed main(){
          string n;
          cin>>n;
          for(int i=0;i<n.size();i++){
                  if(n[i]=='9'){
                          cout<<"Yes";
                          return 0;
                  }
          }
          cout<<"No";
        
}

        
