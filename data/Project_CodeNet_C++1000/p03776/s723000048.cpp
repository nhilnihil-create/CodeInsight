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


ll cmb[100][100];
int main(){
   rep(i, 55){
      rep(j, i + 1){
         if(j == 0 || j == i)cmb[i][j] = 1;
         else cmb[i][j] = cmb[i - 1][j - 1] + cmb[i - 1][j];
      }
   }
   int n, a, b;
   cin >> n >> a >> b;
   a--;b--;
   vector<ll> v(n);
   map<ll, ll> mp;
   rep(i, n){
      cin >> v[i];
      mp[v[i]]++;
   }
   sort(ALL(v), greater<ll>());
   ll sum = 0;
   long double res = 0;
   vector<int> que;
   rep(i, a)sum += v[i];
   REP(i, a, b){
      sum += v[i];
      if(res < (long double)sum / (i + 1)){
         que = vector<int>(0);
         que.push_back(i);
         res = (long double)sum / (i + 1);
      }
      else if(res == (long double)sum / (i + 1)){
         que.push_back(i);
      }
   }
   map<ll, ll> mpp;
   que.push_back(INF);
   ll ans = 0;
   rep(i, n){
      mpp[v[i]]++;
      if(i == *lower_bound(ALL(que), i)){
         ll tmp = 1;
         for(auto p : mpp){
            tmp *= cmb[mp[p.first]][p.second];
         }
         ans += tmp;
      }
   }
   cout << fixed << setprecision(10) << res << endl;
   cout << ans << endl;
   //rep(i, (int)que.size())cout << que[i] << " ";
}
