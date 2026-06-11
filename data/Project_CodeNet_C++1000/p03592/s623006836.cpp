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
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    bool f = false;
    rep(i, m+1)if(n * i == k)f = true;
    rep(i, n+1)if(m * i == k)f = true;

    REP(i, 1, n){
        ll sum = m * i;
        REP(j, 1, m){
            sum = sum - i + n - i;
            if(sum == k)f = true;
        }
    }
    cout << (f ? "Yes" : "No") << endl;
}