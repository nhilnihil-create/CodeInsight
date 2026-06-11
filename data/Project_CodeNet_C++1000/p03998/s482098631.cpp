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
using P = pair<char,int>;

const ll MOD = INF + 7;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    int na = 0, nb = 0, nc = 0;
    int sa = a.size(), sb = b.size(), sc = c.size();
    int now = 0;
    while(1){
        if(now == 0){
            if(a[na] == 'a'){
                now = 0;
                na++;
            }
            else if(a[na] == 'b'){
                now = 1;
                na++;
            }
            else if(a[na] == 'c'){
                now = 2;
                na++;
            }
            if(na == sa && now == 0){
                cout << 'A';
                return 0;
            }
        }
        else if(now == 1){
            if(b[nb] == 'a'){
                now = 0;
                nb++;
            }
            else if(b[nb] == 'b'){
                now = 1;
                nb++;
            }
            else if(b[nb] == 'c'){
                now = 2;
                nb++;
            }
            if(nb == sb && now == 1){
                cout << 'B';
                return 0;
            }
        }
        else if(now == 2){
            if(c[nc] == 'a'){
                now = 0;
                nc++;
            }
            else if(c[nc] == 'b'){
                now = 1;
                nc++;
            }
            else if(c[nc] == 'c'){
                now = 2;
                nc++;
            }
            if(nc == sc && now == 2){
                cout << 'C';
                return 0;
            }
        }
    }
}