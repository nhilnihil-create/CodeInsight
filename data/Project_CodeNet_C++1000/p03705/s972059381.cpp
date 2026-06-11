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
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
     
//const ll MOD = INF + 7;
//Combination MOD
const int MOD = 1e9 + 7;
     
int main(){
   ll n, a, b;
   cin >> n >> a >> b;
   bool f = false;
   if(a > b)f = true;
   if(n == 1 && a != b)f = true;
   if(f){
      cout << 0 << endl;
      return 0;
   }
   else if(n == 1){
      if(a == b)cout << 1 << endl;
      else cout << 0 << endl;
      return 0;
   }
   else {
      ll mx = a + b + (n - 2) * b;
      ll mn = a + b + (n - 2) * a;
      cout << mx - mn + 1 << endl; 
   }
}