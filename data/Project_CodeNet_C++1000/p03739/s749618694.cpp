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

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}



int main(){
    int n;cin>>n;
   vector<ll>sum(n);
   cin>>sum[0];
   rep(i,n-1){
       int a;cin>>a;
       sum[i+1] = sum[i]+a;
   }
   ll res = 0,cnt = 0;
   rep(i,n){
       ll now = sum[i]+cnt;
       if(i%2==0){
           if(now>=0){
               res += abs(-1-now);
               cnt += (-1-now);
           }
       }
           else {
               if(now<=0){
                   res += abs(1-now);
                   cnt += (1-now);
               }
           }
       
   }
   cnt = 0;
   ll ress = 0;
   rep(i,n){
       ll now = sum[i]+cnt;
       if(i%2==0){
           if(now<=0){
               ress += abs(1-now);
               cnt += (1-now);
           }
       }
           else {
               if(now>=0){
                   ress += abs(-1-now);
                   cnt += (-1-now);
               }
           }
       
   }
   cout<<min(res,ress)<<endl;
}

