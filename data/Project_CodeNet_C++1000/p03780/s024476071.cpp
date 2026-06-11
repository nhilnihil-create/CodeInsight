#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

template<typename T>
struct CumulativeSum{
private:
    vector<T> s;
public:
    void init(vector<T>& v){
        s.push_back(0);
        for(int i=0; i<v.size(); i++){
            s.push_back(s.back() + v[i]);
        }
    }
    T sum(int l, int r){
        l = (l < 0 ? 0 : l);
        r = (r >= s.size() ? s.size()-1 : r);
        return s[r] - s[l];
    }
};

int N, K;
int a[5000];

bool dpL[5000][5000] ={}, dpR[5000][5000] ={};
CumulativeSum<int> sumR[5000];

signed main(){
    scanf("%d%d", &N, &K);
    rep(i, N){
        scanf("%d", a+i);
        a[i] = min(a[i], K);
    }

    rep(i, N){
        if(i == 0){
            dpL[0][0] = true;
            if(a[i] < K) dpL[0][a[i]] = true;;
        }
        else{
            rep(j, K){
                dpL[i][j] = dpL[i-1][j];
                if(j-a[i] >= 0) dpL[i][j] |= dpL[i-1][j-a[i]];
            }
        }
    }

    for(int i=N-1; i>=0; i--){
        if(i == N-1){
            dpR[N-1][0] = true;
            if(a[i] < K) dpR[N-1][a[i]] = true;
        }
        else{
            rep(j, K){
                dpR[i][j] = dpR[i+1][j];
                if(j-a[i] >= 0) dpR[i][j] |= dpR[i+1][j-a[i]];
            }
        }
    }
    rep(i, N){
        vector<int> tmp(K, 0);
        rep(j, K) tmp[j] = dpR[i][j];
        sumR[i].init(tmp);
    }

    int ans = 0;
    rep(i, N){
        if(a[i] >= K) continue;
        if(i == 0){
            bool needed = false;
            for(int j=max(0, K-a[0]); j<K; j++){
                needed |= dpR[1][j];
            }
            if(!needed) ans++;
        }
        else if(i == N-1){
            bool needed = false;
            for(int j=max(0,K-a[N-1]); j<K; j++){
                needed |= dpL[N-2][j];
            }
            if(!needed) ans++;
        }
        else{
            bool needed = false;
            rep(j, K){
                if(!dpL[i-1][j]) continue;
                needed |= (sumR[i+1].sum(K-j-a[i], K-j) > 0);
            }
            if(!needed) ans++;
        }
    }
    printf("%d\n", ans);
}