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

const int MOD = INF + 7;
int main(){
   int n;
   string s, t;
   cin >> n >> s >> t;
   ll res = 1;

   int f = -1;          //0 : s[i] == t[i] / 1 : s[i] != t[i]
   rep(i, n){
       if(s[i] == t[i]){
           if(f == -1){
               res *= 3;
           }
           else if(f == 0){
               res *= 2;
           }

           res %= MOD;
           f = 0;
       }


       else {
           if(f == -1){
               res *= 6;
           }
           else if(f == 0){
               res *= 2;
           }
           else if(f == 1){
               res *= 3;
           }

           res %= MOD;
           f = 1;
           i++;
       }
     //cout << res << endl;
   }

   cout << res << endl;
}

