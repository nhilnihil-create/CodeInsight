        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX =2000007;
const int MOD = 998244353;
//
int modpow(int a, int n, int mod) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
     signed main(){
  string s;
  cin>>s;
  for(int i=s.size()/2-1;i>=0;i--){
      bool t=true;
      for(int j=0;j<i;j++){
          if(s[j]!=s[i+j])t=false;
      }
      if(t){
          cout<<i*2<<endl;
          return 0;
      }
  }

     }


 


 






    





      

        
