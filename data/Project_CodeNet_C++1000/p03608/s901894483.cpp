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
#include <cassert>
#include <cmath>
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
using P = pair<int,int>;


int main(){
   int n, m, R;
   cin >> n >> m >> R;
   VEC(int, r, R);

   ll d[n+10][n+10];
   rep(i, n + 10){
       rep(j, n + 10){
           if(i == j)d[i][j] = 0;
           else d[i][j] = INF * INF;
       }
   }

   rep(i, m){
       int a, b, c;
       cin >> a >> b >> c;
       d[a][b] = c;
       d[b][a] = c;
   }

   //warshall_floyd
   rep(k, n + 1){
       rep(i, n + 1){
           rep(j, n + 1){
               d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
           }
       }
   }

   ll res = INF * INF;
  sort(ALL(r));
   do{
       ll sum = 0;
       rep(i, R - 1){
           sum += d[ r[i] ][ r[i + 1] ];
       }

       res = min(res, sum);
   }while( next_permutation( ALL(r) ) );
   cout << res << endl;
}

