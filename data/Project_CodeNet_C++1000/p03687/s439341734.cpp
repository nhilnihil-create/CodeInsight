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
     
    #define INF 1e18
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const int MOD = 1e9 + 7;



int main(){
   string s;
   cin >> s;
   int n = s.size();
   bool f = true;
   rep(i, n){
      if(i == 0)continue;
      else if(s[i] != s[i - 1])f = false;
   }
   if(f){
      cout << 0 << endl;
      return 0;
   }
   map<char, int> mp;
   rep(i, 26){
      char c = ('a' + i);
      int cnt = 0;
      rep(j, n){
         if(s[j] == c){
            mp[c] = max(mp[c], cnt);
            cnt = 0;
         }
         else cnt++;
      }
      mp[c] = max(mp[c], cnt);
   }
   int res = INF;
   for(auto m : mp){
      res = min(res, m.second);
   }
   cout << res << endl;
}
