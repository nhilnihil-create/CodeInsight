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
using P = pair<ll, ll>;

const ll MOD = INF + 7;

const double pi = 3.14159265358979323846264338327950288419716939937510;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    sort(ALL(a));
    bool f;
    if(sum % 10 == 0)f = false;
    else f = true;
    if(!f){
        rep(i, n)if(a[i] % 10 != 0){
            sum -= a[i];
            f = true;
            break;
        }
    }
    cout << (f ? sum : 0) << endl;
}


