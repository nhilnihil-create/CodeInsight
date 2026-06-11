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

vector<int>bitSearch(int bit,int N){
    vector<int>S;
    rep(i,N)if(bit & (1<<i))S.push_back(i);
    return S;
}

int main(){
    int n,k;cin>>n>>k;
    VEC(ll,a,n);

    ll res = INF*INF;
    for(int bit=0;bit<(1<<n);bit++){
        vector<int>S = bitSearch(bit,n);
        ll cost = 0,mx = 0;
        if(S.size()<k)continue;
        rep(i,n){
            if(i==*lower_bound(ALL(S),i) && mx>=a[i]){
                cost += mx-a[i]+1;
                mx++;
            }
            mx = max(mx,a[i]);
            //cout<<mx<<endl;
        }
        res = min(res,cost);
    }
    cout<<res<<endl;
}

