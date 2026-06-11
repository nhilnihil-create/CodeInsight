      #include <iostream>
      #include <string>
      #include <vector>
      #include <algorithm>
      #include <utility>
      using namespace std;
      typedef long long ll;
      #define rep(i, n) for (int i=0;i < (int)(n);i++)



      int main(){
         int n,x;
         cin >> n >> x;
         vector<int> v(n);
         rep(i,n) cin >> v[i];
         int crnt = v[0]+v[1];
         ll ans =0;
         if (crnt > x){
            if (crnt-x <= v[1]) {
               v[1]-= (crnt-x);
               ans += ll(crnt-x);
            }else{
               v[1] =0;
               ans+=ll(crnt-x);
            } 
         }
         for (int i=2;i < n;i++){
            crnt = v[i-1]+v[i];
            if (crnt > x){
               if (crnt-x <= v[i]) {
                  v[i]-= (crnt-x);
                  ans += ll(crnt-x);
               }else{
                  v[i] =0;
                  ans+=ll(crnt-x);
               }
            } 
         }
         cout << ans << endl;
         
         return 0;
         
      }

