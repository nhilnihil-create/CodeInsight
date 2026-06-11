    #include<iostream>
    #include<stdio.h>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<float.h>
    #include<iomanip>
    #include<algorithm>
    #include<string>
    #include<cstring>
    #include<math.h>
    #include<cmath>
    #include<sstream>
    #include<set>
    #include<map>
    #include<queue>
    #include<cassert>
    #include<cmath>
    #include<cstdint>
     
    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const int MOD = 1e9 + 7;




int main(){
   int n;
   cin >> n;
   vector<ll> t(n), a(n);
   rep(i, n)cin >> a[i];
   rep(i, n)cin >> t[i];

   bool f = true;
   vector<ll> mnt(n, -1);
   rep(i, n){
      if(i == 0 || a[i] != a[i - 1]){
         if(a[i] > t[i])f = false;
         mnt[i] = a[i];
      }
   }
   for(int i = n - 1; i >= 0; i--){
      if(i == n - 1 || t[i] != t[i + 1]){
         if(t[i] > a[i])f = false;
         //if(mnt[i] != t[i])f = false;
         mnt[i] = t[i];
      }
   }

   if(!f){
      cout << 0 << endl;
      return 0;
   }
   ll res = 1;
   rep(i, n){
      //cout << mnt[i] << " ";
      if(mnt[i] != -1)continue;
      res = (res * min(a[i], t[i])) % MOD;
      if(res < 0)res += MOD;
   }
   res %= MOD;
   cout << res << endl;
}
