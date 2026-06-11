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

int d[100][100];             //スタートからの距離を保存
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
   int h, w, n;
   cin >> h >> w >> n;
   vector<int>a(n);
   rep(i, n)cin >> a[i];
   int mem[h][w];


   int cnt = 0;
   rep(i, h){
       if(i % 2 == 0){
           rep(j, w){
               mem[i][j] = cnt + 1;
               a[cnt]--;
               if(a[cnt] == 0)cnt++;
           }
       }

       else {
           for(int j = w - 1; j >= 0; j--){
               mem[i][j] = cnt + 1;
               a[cnt]--;
               if(a[cnt] == 0)cnt++;
           }
       }
   }
   rep(i, h){
       rep(j, w)cout << mem[i][j] << " ";
       cout << endl;
   }
}

