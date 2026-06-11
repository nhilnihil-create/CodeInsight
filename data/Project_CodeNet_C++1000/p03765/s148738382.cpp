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
   string s, t;
   cin >> s >> t;
   vector<int> a(s.size()), b(t.size());
   rep(i, (int)s.size()){
      if(s[i] == 'A')a[i] = 1;
      else a[i] = 2;
   }
   rep(i, (int)t.size()){
      if(t[i] == 'A')b[i] = 1;
      else b[i] = 2;
   }

   rep(i, (int)s.size()){
      if(i == 0)continue;
      a[i] += a[i - 1];
      a[i] %= 3;
   }
   rep(i, (int)t.size()){
      if(i == 0)continue;
      b[i] += b[i - 1];
      b[i] %= 3;
   }

   int Q;
   cin >> Q;
   rep(i, Q){
      int al, ar, bl, br;
      cin >> al >> ar >> bl >> br;
      al--;ar--;bl--;br--;
      int sn, tn;
      if(al == 0)sn = a[ar];
      else sn = a[ar] - a[al - 1];

      if(bl == 0)tn = b[br];
      else tn = b[br] - b[bl - 1];

      if(sn < 0)sn += 3;
      if(tn < 0)tn += 3;

      if(sn == tn)cout << "YES" << endl;
      else cout << "NO" << endl;
   }
}
