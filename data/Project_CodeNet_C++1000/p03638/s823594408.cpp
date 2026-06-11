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

int H, W, N;
int a[100000];

signed main(){
    cin >> H >> W >> N;
    rep(i, N) cin >> a[i];
    int k = 0;
    rep(i, H){
        vector<int> ans;
        rep(j, W){
            ans.pb(k+1);
            a[k]--;
            if(a[k] == 0) k++;
        }
        if(i%2) reverse(all(ans));
        rep(j, W){
            if(j != 0) cout << " ";
            cout << ans[j];
        }
        cout << endl;
    }
}