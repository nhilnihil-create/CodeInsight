      #include <iostream>
      #include <string>
      #include <vector>
      #include <algorithm>
      using namespace std;
      typedef long long ll;
      #define rep(i,n) for (int i=0;i < (int)(n);i++)
      
      int v[100001];
      int main(){
        int n;
        cin >> n;
        rep(i,n){
          int l,r;
          cin >> l >> r;
          for (int i=l-1;i < r;i++){
            v[i] = 1;
          }
        }
        int ans = 0;
        rep(i,100000){
          ans += v[i];
        }
        cout << ans << endl;
        
        return 0;

        
      }
        
        