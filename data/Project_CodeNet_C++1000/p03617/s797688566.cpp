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
    #include<numeric>
    #include<array>
     
    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
    #define Vl vector<ll>
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
const ll MOD = 1e9 + 7;
const ll ZER = 0;

int main(){
   ll c[4];
   rep(i, 4)cin >> c[i];
   ll a[4] = {8, 4, 2, 1};
   ll n;
   cin >> n;
   vector<P> p(4);
   rep(i, 4){
       p[i] = P(c[i] * a[i], i);
   }
   ll res = 0;
   sort(ALL(p));
   if(p[0].second == 3){
       int ii = p[1].second;
       res = c[3] * (n / 2);
     //cout << res << endl;
       n %= 2;
       if(ii == 0)res += c[ii] * n * 4;
       if(ii == 1)res += c[ii] * n * 2;
       if(ii == 2)res += c[ii] * n;
   }
   else {
       int ii = p[0].second;
       if(ii == 0)res = c[ii] * n * 4;
       if(ii == 1)res = c[ii] * n * 2;
       if(ii == 2)res = c[ii] * n;
   }
   cout << res << endl;
}
