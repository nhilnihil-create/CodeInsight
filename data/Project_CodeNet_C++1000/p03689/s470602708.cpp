#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
ll d[501][501];
int main(){
    int n,m,h,w;
    cin >> n >> m >> h >> w;
    rep(i,n){
        rep(j,m){
            d[i][j] = 1000;
        }
    }
    for(int i=h-1;i<n;i+=h){
        for(int j=w-1;j<m;j+=w){
            d[i][j] = -1000*h*w+999;
        }
    }
    ll sm = 0;
    rep(i,n){
        rep(j,m){
            sm += d[i][j];
        }
    }
    if(sm<=0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        rep(i,n){
            rep(j,m){
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}