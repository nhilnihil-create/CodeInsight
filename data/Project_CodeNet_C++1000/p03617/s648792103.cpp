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
    VEC(ll,cost,4);
    ll n;cin>>n;
    vector<pair<ll,int>>r;
    rep(i,4){
        r.emplace_back(cost[i]*pow(2,3-i),i);
    }
    sort(ALL(r));
    vector<int>o(4);
    rep(i,4){
        o[i] = r[i].second;
    }
    ll res = 0;
    for(auto c : o){
        ll m = n;
        if(c==0){
            res += cost[c]*m*4;
            break; 
        }
        if(c==1){
            res += cost[c]*m*2;
            break; 
        }
        if(c==2){
            res += cost[c]*m;
            break; 
        }
        if(c==3){
            n -= 2*(m/2);
            res += cost[c]*(m/2);
        }
    }
    cout<<res<<endl;
}

